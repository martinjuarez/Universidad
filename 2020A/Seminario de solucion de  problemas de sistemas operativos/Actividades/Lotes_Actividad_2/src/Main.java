import java.util.ArrayList;

import java.util.Scanner;

public class Main {

	private int MAX_PROCESSES = 4;
	private ArrayList<Batch> batchList = new ArrayList<Batch>();
	private int timeElapsed = 0;
	private int timeRemaning = 0;

	private void showBatch() {
		int totalBatch = batchList.size();
		ArrayList<Process> finishProcesses = new ArrayList<Process>();
		for (int i = 0; i < totalBatch; i++) {
			System.out.println("Numero de lotes pendientes: " + (totalBatch - (i + 1)));
			Batch batch = batchList.get(i);
			ArrayList<Process> processList = batch.getProcessList();
			for (int j = 0; j < processList.size(); j++) {
				Process process = processList.get(j);
				System.out.println("Lote en Ejecucion: ");
				System.out.println("Numero de programa: " + process.getId());
				System.out.println("Tiempo maximo estimado: " + process.getMaxTime());
				this.timeRemaning = this.timeRemaning + process.getMaxTime();
			}
			for (int j = 0; j < processList.size(); j++) {
				Process process = processList.get(j);
				System.out.println("\n\n");
				System.out.println("Proceso en Ejecucion: ");
				System.out.println("Nombre: " + process.getProgrammerName());
				System.out.println("Operacion: " + process.getOperation());
				System.out.println("Tiempo maximo estimado: " + process.getMaxTime());
				System.out.println("Numero de programa: " + process.getId());
				System.out.println("Tiempo restante: ");
				for (int k = process.getMaxTime(); k >= 0; k--) {
					 try {
						 System.out.print("    " + k);
						Thread.sleep(1000);
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
				finishProcesses.add(process);
				this.timeElapsed = this.timeElapsed + process.getMaxTime();
				this.timeRemaning = this.timeRemaning - process.getMaxTime();

				System.out.println("\n\n\nProceso Terminados: ");
				for (int k = 0; k < finishProcesses.size(); k++) {
					Process finishProcess = finishProcesses.get(k);
					System.out.println("Numero de programa: " + finishProcess.getId());
					String operation = finishProcess.getOperation();
					System.out.println("Operacion y datos: " + operation);
					int result = operationResult(operation);
					System.out.println("Resultado de la operacion: " + result);
				}
			}
			System.out.println("-------------------------------------");
		}
	}

	private void addOperation(Process process, Scanner input) {
		try {
			System.out.println("> Operación a realizar: ");
			process.setOperation(input.next());
		} catch (Exception error) {
			System.out.println(error.getMessage());
			addOperation(process, input);
		}
	}

	private void addTime(Process process, Scanner input) {
		try {
			System.out.println("> Tiempo máximo estimado: ");
			process.setMaxTime(input.nextInt());
		} catch (Exception error) {
			System.out.println(error.getMessage());
			addTime(process, input);
		}
	}

	private void addId(Process process, Scanner input) {
		int totalBatch = batchList.size();
		System.out.println("> Id: ");
		String id = input.next();

		boolean idExist = false;
		for (int i = 0; i < totalBatch; i++) {
			Batch batch = batchList.get(i);
			ArrayList<Process> processList = batch.getProcessList();
			for (int j = 0; j < processList.size(); j++) {
				Process currentProcess = processList.get(j);
				String currentId = currentProcess.getId();
				if (id.equals(currentId)) {
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
			addId(process, input);
		} else {
			process.setId(id);
		}
	}

	private void addProcesses(int processNumber) {
		int count = (int) Math.ceil((processNumber + MAX_PROCESSES - 1) / MAX_PROCESSES);
		int processesCount = 0;
		Scanner input = new Scanner(System.in);

		for (int i = 0; i < count; i++) {
			Batch batch = new Batch();
			for (int j = 0; j < MAX_PROCESSES && processesCount < processNumber; j++) {
				Process process = new Process();
				try {
					System.out.println("> Nombre del programador: ");
					process.setProgrammerName(input.next());
					addOperation(process, input);
					addTime(process, input);
					addId(process, input);
					batch.setProcess(process);
					processesCount++;
				} catch (Exception error) {
					System.out.println(error.getMessage());
				}
			}
			batchList.add(batch);
		}
		input.close();
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
		Main main = new Main();
		main.addProcesses(processNumber);
		main.showBatch();
		input.close();
		long endTime = System.currentTimeMillis();
		long miliseconds = endTime - startTime;
		int minutes = (int) Math.floor(miliseconds / 60000);
		int seconds = (int) ((miliseconds % 60000) / 1000);
		System.out.println("Tiempo de ejecucion del programa: " + minutes + ":" + (seconds < 10 ? "0" : "") + seconds);
	}

}
