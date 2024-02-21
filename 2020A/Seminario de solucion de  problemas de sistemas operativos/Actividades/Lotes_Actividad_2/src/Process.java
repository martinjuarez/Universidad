import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Process {
	 String programmerName = "";
	 String operation = "";
	 int maxTime = 0;
	 String id = "";
	
	public String getProgrammerName() {
		return programmerName;
	}
	public void setProgrammerName(String programmerName) {
		this.programmerName = programmerName;
	}
	public String getOperation() {
		return operation;
	}
	public void setOperation(String operation) throws Exception {
		 Pattern pattern = Pattern.compile("([\\d]+[/\\*\\-+%^][\\d]+)");
		 Matcher matcher = pattern.matcher(operation);
		 boolean isValidOperation = matcher.matches();
		
		if(isValidOperation) {
			this.operation = operation;
		}
		else {
			throw new Exception("La operacion es invalida");
		}
	}
	public int getMaxTime() {
		return maxTime;
	}
	public void setMaxTime(int maxTime) throws Exception {
		if(maxTime > 0) {
			this.maxTime = maxTime;
		}
		else {
			throw new Exception("El tiempo debe ser mayor que 0");
		}
		
	}
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
	}
	
	
}
