/**
 * Class that represents a computer.
 */
public class Computer {
	// Data Fields
	private String manufacturer;
	private String processor;
	private double ramSize;
	private int diskSize;
	protected double processorSpeed;

	// Methods
	/**
	 * Initializes a Computer object with all properties specified.
	 * 
	 * @param man       The computer manufacturer
	 * @param proc      The processor type
	 * @param ram       The RAM size
	 * @param disk      The disk size
	 * @param procSpeed The processor speed
	 */
	public Computer(String man, String proc, double ram, int disk, double procSpeed) {
		manufacturer = man;
		processor = proc;
		ramSize = ram;
		diskSize = disk;
		processorSpeed = procSpeed;
	}

	public double getRamSize() {
		return ramSize;
	}

	public double getProcessorSpeed() {
		return processorSpeed;
	}

	public int getDiskSize() {
		return diskSize;
	}

	public String toString() {
		String result = "Manufacturer: " + manufacturer + "\nCPU: " + processor + "\nRAM: " + ramSize + " gigabytes"
				+ "\nDisk: " + diskSize + " gigabytes" + "\nProcessor speed: " + processorSpeed + " gigahertz";

		return result;
	}

	/**
	 * Evaluate the power of this computer for purposes of installing or running
	 * software. power is RAM size times processor speed
	 * 
	 * @return the power.
	 */
	public double computePower() {
		// TODO: change this to the actual compute power
		return 0;
	}
}
