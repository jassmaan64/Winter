package hwdp;

public interface Subject {
	// TODO HWDP P3
	void attach(Observer observer);

	void detach(Observer observer);

	void notifyObservers();

	String getStateName();

	String getBookName();
}
