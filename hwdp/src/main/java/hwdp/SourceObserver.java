package hwdp;

import java.util.HashMap;

// TODO HWDP P3

public class SourceObserver implements Observer {
	private String name;
	private HashMap<Subject, String> sourceStateTracker;

	public SourceObserver(String n) {
		// TODO?
		name = n;
		sourceStateTracker = new HashMap<Subject, String>();
	}

	@Override
	public void update(Subject o) {
		// TODO?
		String lastState = sourceStateTracker.getOrDefault(o, "UNOBSERVED");
		LibraryLogger.getInstance().writeLine(name + " OBSERVED " + o.getBookName() + " LEAVING STATE: " + lastState);
		sourceStateTracker.put(o, o.getStateName());
	}

	@Override
	public String toString() {
		return name;
	}
}
