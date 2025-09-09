package hwdp;

// TODO HWDP P2
class GotBack extends LBState {
    private static GotBack instance;

    private GotBack() {
    }

    public static GotBack getInstance() {
        if (instance == null) {
            instance = new GotBack();
        }
        return instance;
    }

    public void shelf(LibraryBook book) {
        logTransition(instance, OnShelf.getInstance());
        book.setState(OnShelf.getInstance());
        // throw new BadOperationException("BadOperationException - Can't use shelf in
        // Borrowed state");
    }

    public void issue(LibraryBook book) throws BadOperationException {
        throw new BadOperationException("BadOperationException - Can't use issue in GotBack state");
        // logTransition(instance, Borrowed.getInstance());
        // book.setState(Borrowed.getInstance());
    }

    public void extend(LibraryBook book) throws BadOperationException {
        throw new BadOperationException("BadOperationException - Can't use extend in GotBack state");
        // logTransition(instance, Borrowed.getInstance());
        // book.setState(Borrowed.getInstance());
    }

    public void returnIt(LibraryBook book) throws BadOperationException {
        // logTransition(instance, GotBack.getInstance());
        // book.setState(GotBack.getInstance());
        throw new BadOperationException("BadOperationException - Can't use returnIt in GotBack state");
    }

    public String toString() {
        return "GotBack";
    }
}