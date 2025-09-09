package hw3;

import java.util.Arrays;
import java.util.List;

public class SummaryGenerator{
    private TaskManager taskmanager;

    public SummaryGenerator(TaskManager taskman) {
        taskmanager = taskman;
    }

    public void generateSummary() {
        List<String> tasksData = taskmanager.getDataStorage().readTask();
        for (String data : tasksData) {
            String[] brokenPart = data.split(" ");
            // String taskType = brokenPart[0];
            String taskName = brokenPart[1];
            String taskDesc = String.join(" ", Arrays.copyOfRange(brokenPart, 2, brokenPart.length));

            System.out.println("Task: " + taskName + ", Description: " + taskDesc);
        }
    }

    public double calculateMin() {
        return taskmanager.getTasks().values().stream()
                .filter(task -> task.getStarTime() != null && task.getEndTime() != null)
                .mapToLong(Task::getDuration)
                .min()
                .orElse(0) / 60.0;
    }

    public double calculateMax() {
        return taskmanager.getTasks().values().stream()
                .filter(task -> task.getStarTime() != null && task.getEndTime() != null)
                .mapToLong(Task::getDuration)
                .max()
                .orElse(0) / 60.0;
    }

    public double calculateAvg() {
        return taskmanager.getTasks().values().stream()
                .filter(task -> task.getStarTime() != null && task.getEndTime() != null)
                .mapToLong(Task::getDuration)
                .average()
                .orElse(0) / 60.0;
    }
};
