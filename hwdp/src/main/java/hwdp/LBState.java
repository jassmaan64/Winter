package hwdp;

// TODO HWDP P2
abstract class LBState {
    public abstract void shelf(LibraryBook book) throws BadOperationException;

    public abstract void issue(LibraryBook book) throws BadOperationException;

    public abstract void extend(LibraryBook book) throws BadOperationException;

    public abstract void returnIt(LibraryBook book) throws BadOperationException;

    public void logTransition(LBState fromState, LBState toState) {
        LibraryLogger.getInstance().writeLine("Leaving State " + fromState + " for State " + toState);
    }
}