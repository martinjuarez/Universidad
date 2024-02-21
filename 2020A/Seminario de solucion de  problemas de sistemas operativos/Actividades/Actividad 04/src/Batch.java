import java.util.ArrayList;

public class Batch {

	ArrayList<Process> processList = new ArrayList<Process>();
	

	public void setProcess(Process process) {
		processList.add(process);
	}
	
	public ArrayList<Process> getProcessList() {
		return processList;
	}
	
	public void showProcessList(){
		System.out.println(processList);
	}
}
