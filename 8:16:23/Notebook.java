/**
 * Class that represents a notebook computer.
 */
public class Notebook extends Computer {
	// Data Fields
	private double screenSize;
	private double weight;

	// Methods
	/**
	 * Initializes a Notebook object with all properties specified.
	 * 
	 * @param man       The computer manufacturer
	 * @param proc      The processor type
	 * @param ram       The RAM size
	 * @param disk      The disk size
	 * @param procSpeed The processor speed
	 * @param screen    The screen size
	 * @param wei       The weight
	 */
	public Notebook(String man, String proc, double ram, int disk, double procSpeed, double screen, double wei) {
		// TODO: initialize all properties. 
		// Hint: use super(...) for parent properties. Also set Notebook's properties.
		super("", "", 0, 0, 0); // change this
		
	}

	public String toString() {
		String result = super.toString() + "\nScreen Size: " + screenSize + " inches" + "\nWeight:  " + weight
				+ " pounds";
		return result;
	}

	public double getScreenSize() {
		return screenSize;
	}

	public double getWeight() {
		return weight;
	}

	/**
	 * Special compute power method for Notebook. Because notebooks overheat easily,
	 * their power rating is half of a computer's.
	 */

	public double computePower() {
		// TODO: Change this
		System.out.println();
		return 0;
	}
}
