package hwdp;

// TODO HWDP P2
class Borrowed extends LBState {
    private static Borrowed instance;

    private Borrowed() {
    }

    public static Borrowed getInstance() {
        if (instance == null) {
            instance = new Borrowed();
        }
        return instance;
    }

    public void shelf(LibraryBook book) throws BadOperationException {
        throw new BadOperationException("BadOperationException - Can't use shelf in Borrowed state");
    }

    public void issue(LibraryBook book) throws BadOperationException {
        throw new BadOperationException("BadOperationException - Can't use extend in Borrowed state");
        // logTransition(instance, Borrowed.getInstance());
        // book.setState(Borrowed.getInstance());
    }

    public void extend(LibraryBook book) {
        // throw new BadOperationException("BadOperationException - Can't use extend in
        // OnShelf state");
        logTransition(instance, Borrowed.getInstance());
        book.setState(Borrowed.getInstance());
    }

    public void returnIt(LibraryBook book) {
        logTransition(instance, GotBack.getInstance());
        book.setState(GotBack.getInstance());
        // throw new BadOperationException("BadOperationException - Can't use returnIt
        // in OnShelf state");
    }

    public String toString() {
        return "Borrowed";
    }
}