package hw3;

import java.time.LocalDateTime;
import java.util.*;
import java.util.stream.Collectors;

public class TaskManager {
    private Map<String, Task> tasks;
    private DataStorage dataStorage;

    public TaskManager(DataStorage dataSto) {
        tasks = new HashMap<>();
        dataStorage = dataSto;
    }

    public void startTask(String taskName) {
        Task task = tasks.computeIfAbsent(taskName, t -> new Task());
        task.setStarTime(LocalDateTime.now());
        dataStorage.writeTask("Start", taskName, LocalDateTime.now().toString());
    }

    public void stopTask(String taskName) {
        Task task = tasks.get(taskName);
        if (task != null) {
            task.setEndTime(LocalDateTime.now());
            dataStorage.writeTask("STOP", taskName, LocalDateTime.now().toString());
        }
    }

    public void describeTask(String taskName, String description, String size) {
        Task task = tasks.get(taskName);
        if (task != null) {
            task.setDescription(description);
            task.setSize(size);
            dataStorage.writeTask("DESCRIBE", taskName, description, size);
        }
    }

    public void setTaskSize(String taskName, String size) {
        Task task = tasks.get(taskName);
        if (task != null) {
            task.setSize(size);
            dataStorage.writeTask("SIZE", taskName, size);
        }
    }

    public void renameTask(String oldName, String newName) {
        Task task = tasks.remove(oldName);
        if (task != null) {
            task.setName(newName);
            tasks.put(newName, task);
            dataStorage.writeTask("RENAME", oldName, newName);
        }
    }

    public void deleteTask(String taskName) {
        if (tasks.containsKey(taskName)) {
            tasks.remove(taskName);
            dataStorage.writeTask("DELETE", taskName, LocalDateTime.now().toString());
        }
    }

    public String summary() {
        return tasks.values().stream()
                .map(Task::toString)
                .collect(Collectors.joining("\n"));
    }

    /**
     * @return Map<String, Task> return the tasks
     */
    public Map<String, Task> getTasks() {
        return tasks;
    }

    // /**
    // * @param tasks the tasks to set
    // */
    // public void setTasks(Map<String, Task> tasks) {
    // this.tasks = tasks;
    // }

    /**
     * @return DataStorage return the dataStorage
     */
    public DataStorage getDataStorage() {
        return dataStorage;
    }

    // /**
    // * @param dataStorage the dataStorage to set
    // */
    // public void setDataStorage(DataStorage dataStorage) {
    // this.dataStorage = dataStorage;
    // }

}
