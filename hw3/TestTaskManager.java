package hw3;

import java.time.LocalDateTime;

public class TestTaskManager {
    public static void main(String[] args) {
        DataStorage dataStorage = new DataStorage("tasks.txt");

        TaskManager taskManager = new TaskManager(dataStorage);

        // Simulate tasks
        taskManager.startTask("Task1");
        simulateDelay(); 
        simulateDelay();
        simulateDelay();
        taskManager.stopTask("Task1");

        taskManager.startTask("Task2");
        simulateDelay(); 
        taskManager.describeTask("Task2", "Description for Task 2", "M");
        taskManager.stopTask("Task2");

        SummaryGenerator summaryGenerator = new SummaryGenerator(taskManager);

        System.out.println("Task Summary:");
        summaryGenerator.generateSummary();

        System.out.println("Min Duration: " + summaryGenerator.calculateMin() + " minutes");
        System.out.println("Max Duration: " + summaryGenerator.calculateMax() + " minutes");
        System.out.println("Avg Duration: " + summaryGenerator.calculateAvg() + " minutes");
    }

    private static void simulateDelay() {
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}