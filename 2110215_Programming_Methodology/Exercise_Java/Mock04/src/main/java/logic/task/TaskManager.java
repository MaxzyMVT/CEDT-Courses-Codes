package logic.task;


import interfaces.Duplicatable;

import java.util.ArrayList;

public class TaskManager {
	public static ArrayList<Task> getTaskByType(ArrayList<Class> types) {
        ArrayList<Task> tasks = TaskList.getTasks();
        ArrayList<Task> returnTasks = new ArrayList<>();

        for (Task task : tasks) {
            for (Class type : types) {
                if(instanceOf(task.getClass(), type)) {
                    returnTasks.add(task);
                    break;
                }
            }
        }

        return returnTasks;
    }
	
    public static void deleteDuplicateTasks() {
        ArrayList<Task> tasks = TaskList.getTasks();
        ArrayList<Task> wantedTasks = new ArrayList<>();
        for (Task task : tasks) {
            if (!(task instanceof Duplicatable) || !task.toString().contains("-")) {
                wantedTasks.add(task);
            }
        }

        TaskList.setTasks(wantedTasks);
    }

    public static boolean instanceOf(Class checkClass, Class interfaceClass) {
        return interfaceClass.isAssignableFrom(checkClass);
    }
}
