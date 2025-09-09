package hw3;

public class TM {
    private static TaskManager taskManager = new TaskManager(new DataStorage("tasks.txt"));

    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("No Command entered");
            return;
        }
        String command = args[0];
        String taskName = args[1];
        String restArgs = args.length > 2 ? args[2] : null;
        switch (command) {
            case "start":
                taskManager.startTask(taskName);
                break;
            case "stop":
                taskManager.stopTask(taskName);
                break;
            case "describe":
                String desc = restArgs != null ? restArgs : "";
                String size = args.length > 3 ? args[3] : null;
                taskManager.describeTask(taskName, desc, size);
                break;
            case "size":
                if(restArgs != null)
                {
                    taskManager.setTaskSize(taskName, restArgs);
                }
                break;
            case "rename":
                if(args.length > 3)
                {
                    String newName = args[3];
                    taskManager.renameTask(taskName, newName);
                }
                break;
            case "delete":
                taskManager.deleteTask(taskName);
                break;
            case "summary":
                System.out.println(taskManager.summary());
                break;
            default:
                System.out.println("Command not recoganized");
        }
    }
}
