import java.awt.Robot;
import java.awt.event.KeyEvent;
import java.util.ArrayList;
import java.util.concurrent.locks.ReadWriteLock;
import java.util.concurrent.locks.ReentrantReadWriteLock;
import java.util.Random;
import java.util.Scanner;

public abstract class Main implements Runnable {

	private static int MAX_PROCESSES = 3;
	private static ArrayList<Batch> batchList = new ArrayList<Batch>();
	private static int timeElapsed = 0;
	private static int timeRemaning = 0;
	static String[] operators = { "/", "*", "-", "+", "%", "^" };
	private final ReadWriteLock pause = new ReentrantReadWriteLock();
	private volatile boolean cancelled = false;
	private Exception thrown = null;

	@Override
	public void run() {
		try {
			while (!cancelled) {
				blockIfPaused();
				int counter = step();
				if(counter<0) {
					Robot robot = new Robot();
					cancelled = true;
					robot.keyPress(KeyEvent.VK_ENTER);
				}
			}
		} catch (Exception ex) {
			thrown = ex;
		}
	}

	private void blockIfPaused() throws InterruptedException {
		try {
			pause.writeLock().lockInterruptibly();
		} finally {
			pause.writeLock().unlock();
		}

	}

	public void pause() {
		pause.readLock().lock();
	}

	public void resume() {
		pause.readLock().unlock();
	}

	public void cancel() {
		cancelled = true;
	}

	public void start() {
		new Thread(this).start();
	}


	public Exception getThrown() {
		return thrown;
	}

	public abstract int step() throws Exception;

	public static Main make(Stepper stepper) {
		StepperThread pauseableStepper = new StepperThread(stepper);
		return pauseableStepper;
	}

	public interface Stepper {
		public int step() throws Exception;
	}

	private static class StepperThread extends Main {
		private final Stepper stepper;

		StepperThread(Stepper stepper) {
			this.stepper = stepper;
		}

		@Override
		public int step() throws Exception {
			return stepper.step();
		}
	}

	static int n = 0;

	public static void showBatch() {
		int totalBatch = batchList.size();
		ArrayList<Process> finishProcesses = new ArrayList<Process>();
		for (int i = 0; i < totalBatch; i++) {
			System.out.println("Numero de lotes pendientes: " + (totalBatch - (i + 1)));
			Batch batch = batchList.get(i);
			ArrayList<Process> processList = batch.getProcessList();
			System.out.println("Procesos en espera: ");
			for (int j = 0; j < processList.size(); j++) {
				Process process = processList.get(j);
				System.out.println("Numero de programa: " + process.getId());
				System.out.println("Tiempo maximo estimado: " + process.getMaxTime());
				timeRemaning = timeRemaning + process.getMaxTime();
			}
			for (int j = 0; j < processList.size(); j++) {
				Process process = processList.get(j);
				System.out.println("\n\n");
				System.out.println("Proceso en Ejecucion: ");
				System.out.println("Operacion: " + process.getOperation());
				System.out.println("Tiempo maximo estimado: " + process.getMaxTime());
				System.out.println("Numero de programa: " + process.getId());
				System.out.println("Tiempo restante: ");
				n =  process.getMaxTime();
				boolean isInterrupted = false;
				try {
					Stepper s = new Stepper() {
						@Override
						public int step() throws Exception {
							System.out.println(n);
							Thread.sleep(1000);
							return n -= 1;
						}
					};
					Main t = Main.make(s);
					t.start();
					Scanner d = new Scanner(System.in);
					while(n>=0) {
						String value = d.nextLine();
						if(value.equals("P")) {
							System.out.println("Paused");
							t.pause();
						}
						if(value.equals("C")) {
							System.out.println("Continued");
							t.resume();
						}
						if(value.equals("E")) {
							System.out.println("Error");
							process.setHasError(true);
							t.cancel();
							t.resume();
						}
						if(value.equals("I")) {
							System.out.println("Interruption");
							batch.setProcess(process);
							isInterrupted = true;
							t.cancel();
							t.resume();
						}
					}
					t.cancel();
					
				} catch (Exception e) {
				}

				if(!isInterrupted) {
					finishProcesses.add(process);
					timeElapsed = timeElapsed + process.getMaxTime();
					timeRemaning = timeRemaning - process.getMaxTime();
				}
				
				System.out.println("\n\n\nProceso Terminados: ");
				for (int k = 0; k < finishProcesses.size(); k++) {
					Process finishProcess = finishProcesses.get(k);
					System.out.println("Numero de programa: " + finishProcess.getId());
					String operation = finishProcess.getOperation();
					System.out.println("Operacion y datos: " + operation);
					boolean hasError = finishProcess.isHasError();
					if(hasError) {
						System.out.println("Resultado de la operacion: ERROR");
					}else {
						int result = operationResult(operation);
						System.out.println("Resultado de la operacion: " + result);
					}
				}
			}
			System.out.println("-------------------------------------");
		}
	}

	private static void addOperation(Process process, String operation) {
		try {
			process.setOperation(operation);
		} catch (Exception error) {
			Random rand = new Random();
			System.out.println(error.getMessage());
			String newOperation = rand.nextInt(100) + operators[rand.nextInt(6)] + rand.nextInt(100);
			addOperation(process, newOperation);
		}
	}

	private static void addTime(Process process, int time) {
		try {
			process.setMaxTime(time);
		} catch (Exception error) {
			System.out.println(error.getMessage());
			Random rand = new Random();
			int newTime = rand.nextInt(10) + 6;
			addTime(process, newTime);
		}
	}

	private static void addId(Process process, int id) {
		Random rand = new Random();
		int totalBatch = batchList.size();

		boolean idExist = false;
		for (int i = 0; i < totalBatch; i++) {
			Batch batch = batchList.get(i);
			ArrayList<Process> processList = batch.getProcessList();
			for (int j = 0; j < processList.size(); j++) {
				Process currentProcess = processList.get(j);
				int currentId = currentProcess.getId();
				if (id == currentId) {
					idExist = true;
					break;
				}
			}
			if (idExist) {
				break;
			}
		}
		if (idExist) {
			System.out.println("El ID ya existe en otro proceso");
			int newId = rand.nextInt(25);
			addId(process, newId);
		} else {
			process.setId(id);
		}
	}
	

	private static void addProcesses(int processNumber) {
		Random rand = new Random();
		int count = (int) Math.ceil((processNumber + MAX_PROCESSES - 1) / MAX_PROCESSES);
		int processesCount = 0;

		for (int i = 0; i < count; i++) {
			Batch batch = new Batch();
			for (int j = 0; j < MAX_PROCESSES && processesCount < processNumber; j++) {
				Process process = new Process();
				try {
					String operation = rand.nextInt(100) + operators[rand.nextInt(6)] + rand.nextInt(100);
					addOperation(process, operation);
					int time = rand.nextInt(10) + 6;
					addTime(process, time);
					int id = rand.nextInt(25);
					addId(process, id);
					batch.setProcess(process);
					processesCount++;
				} catch (Exception error) {
					System.out.println(error.getMessage());
				}
			}
			batchList.add(batch);
		}
	}

	private static int operationResult(String operation) {
		String[] numbers = operation.split("[/\\*\\-+%^]", 2);
		String number1 = numbers[0];
		String number2 = numbers[1];
		String operationSymbol = operation.substring(number1.length(), operation.length() - number2.length());

		switch (operationSymbol) {
		case "+":
			return Integer.parseInt(number1) + Integer.parseInt(number2);
		case "-":
			return Integer.parseInt(number1) - Integer.parseInt(number2);
		case "/":
			return Integer.parseInt(number1) / Integer.parseInt(number2);
		case "*":
			return Integer.parseInt(number1) * Integer.parseInt(number2);
		case "%":
			return Integer.parseInt(number1) % Integer.parseInt(number2);
		case "^":
			int result = Integer.parseInt(number1);
			for (int i = 1; i < Integer.parseInt(number2); ++i) {
				result = result * Integer.parseInt(number1);
			}
			return result;
		}
		return 0;
	}

	public static void main(String[] args) {

		long startTime = System.currentTimeMillis();
		int processNumber = 0;
		System.out.println("¿Cuantos procesos desea capturar?");
		Scanner input = new Scanner(System.in);
		processNumber = input.nextInt();
		Main.addProcesses(processNumber);
		Main.showBatch();
		input.close();
		long endTime = System.currentTimeMillis();
		long miliseconds = endTime - startTime;
		int minutes = (int) Math.floor(miliseconds / 60000);
		int seconds = (int) ((miliseconds % 60000) / 1000);
		System.out.println("Tiempo de ejecucion del programa: " + minutes + ":" + (seconds < 10 ? "0" : "") + seconds);

	}

}
