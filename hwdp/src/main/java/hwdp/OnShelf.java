package hwdp;

// TODO HWDP P2
class OnShelf extends LBState {
    private static OnShelf instance;

    private OnShelf() {
    }

    public static OnShelf getInstance() {
        if (instance == null) {
            instance = new OnShelf();
        }
        return instance;
    }

    public void shelf(LibraryBook book) throws BadOperationException {
        throw new BadOperationException("BadOperationException - Can't use shelf in OnShelf state");
    }

    public void issue(LibraryBook book) {
        logTransition(instance, Borrowed.getInstance());
        book.setState(Borrowed.getInstance());
    }

    public void extend(LibraryBook book) throws BadOperationException {
        throw new BadOperationException("BadOperationException - Can't use extend in OnShelf state");
    }

    public void returnIt(LibraryBook book) throws BadOperationException {
        throw new BadOperationException("BadOperationException - Can't use returnIt in OnShelf state");
    }

    public String toString() {
        return "OnShelf";
    }
}