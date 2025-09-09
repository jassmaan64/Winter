package hwdp;

import java.util.HashMap;

// TODO HWDP P3
public class DestObserver implements Observer {
    private String name;
    private HashMap<Subject, String> destinationStateTracker;

    public DestObserver(String named) {
        name = named;
        destinationStateTracker = new HashMap<Subject, String>();
    }

    public void update(Subject observer) {
        LibraryLogger.getInstance()
                .writeLine(
                        name + " OBSERVED " + observer.getBookName() + " REACHING STATE: " + observer.getStateName());
        destinationStateTracker.put(observer, observer.getStateName());
    }

    public String toString() {
        return name;
    }
}