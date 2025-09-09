package hwdp;
// TODO HWDP P2

import java.util.ArrayList;
import java.util.List;

// public class LibraryBook /* implements Subject */ 
public class LibraryBook implements Subject {
    // ^ uncomment for P3
    private LBState stateName;
    private String name;

    private List<Observer> observers = new ArrayList<>();
    // TODO? Are other instance variables needed for this pattern?

    public LibraryBook(String name) {
        // TODO HWDP P2
        this.name = name;
        this.stateName = OnShelf.getInstance();
    }

    /*
     * public LBState getState() {
     * // TODO?
     * }
     */
    public LBState getState() {
        // TODO?
        return stateName;
    }

    public void returnIt() {
        // TODO?
        try {
            stateName.returnIt(this);
        } catch (BadOperationException e) {
            LibraryLogger.getInstance().writeLine("BadOperationException - Can't use returnIt in " + this + " state");
        }

    }

    public void shelf() {
        // TODO?
        try {
            stateName.shelf(this);
        } catch (BadOperationException e) {
            LibraryLogger.getInstance().writeLine("BadOperationException - Can't use shelf in " + this + " state");
        }
    }

    public void extend() {
        // TODO?
        try {
            stateName.extend(this);
        } catch (BadOperationException e) {
            LibraryLogger.getInstance().writeLine("BadOperationException - Can't use extend in " + this + " state");
        }
    }

    public void issue() {
        // TODO?
        try {
            stateName.issue(this);
        } catch (BadOperationException e) {
            LibraryLogger.getInstance().writeLine("BadOperationException - Can't use issue in " + this + " state");
        }
    }

    /*
     * @Override
     * public String toString() {
     * // TODO?
     * }
     */
    public String toString() {
        // TODO?
        return stateName.toString();
    }

    public void setState(LBState state) {
        stateName = state;
        notifyObservers();
    }

    public void attach(Observer observer) {
        if (observers.contains(observer)) {
            LibraryLogger.getInstance().writeLine(observer + " is already attached to " + name);
        } else {
            observers.add(observer);
            LibraryLogger.getInstance().writeLine(observer + " is now watching " + name);
        }
    }

    public void detach(Observer observer) {
        if (observers.remove(observer)) {
            LibraryLogger.getInstance().writeLine(observer + " is no longer watching " + name);
        }
    }

    public void notifyObservers() {
        for (Observer observer : observers) {
            observer.update(this);
        }
    }

    public String getStateName() {
        return stateName.toString();
    }

    public String getBookName() {
        return name.toString();
    }

}