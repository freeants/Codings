

import java.io.File;

public class hwinfo {
    public static void PrintMsg(String Msg, long Num) {
        System.out.printf(Msg + ": %,-30d\n", Num);
    }

    public static void main(String[] args) {
        /* Total number of processors or cores available to the JVM */
        PrintMsg("Total logical processors", Runtime.getRuntime().availableProcessors());

        /* */
        com.sun.management.OperatingSystemMXBean os = (com.sun.management.OperatingSystemMXBean) java.lang.management.ManagementFactory
                .getOperatingSystemMXBean();
        long physicalMemorySize = os.getTotalPhysicalMemorySize()/1024000000;
        long freePhysicalMemorySize = os.getFreePhysicalMemorySize()/1024000000;
        PrintMsg("Total physical mem (GB)", physicalMemorySize);
        PrintMsg("Available phy. mem (GB)", freePhysicalMemorySize);

        /* Total amount of free memory available to the JVM */
        long freeMemory = Runtime.getRuntime().freeMemory()/1024000000;
        System.out.println("Total free logical mem (GB): " + freeMemory);

        /* This will return Long.MAX_VALUE if there is no preset limit */
        long maxMemory = Runtime.getRuntime().maxMemory() /1024000000;
        /* Maximum amount of memory the JVM will attempt to use */
        System.out.println("Maximum memory (GB): " + (maxMemory == Long.MAX_VALUE ? "no limit" : maxMemory));

        /* Total memory currently available to the JVM */
        System.out.println("Total memory available to JVM (bytes): " + Runtime.getRuntime().totalMemory());

        /* Get a list of all filesystem roots on this system */
        File[] roots = File.listRoots();

        /* For each filesystem root, print some info */
        for (File root : roots) {
            System.out.println("File system root: " + root.getAbsolutePath());
            System.out.println("Total space (bytes): " + root.getTotalSpace());
            System.out.println("Free space (bytes): " + root.getFreeSpace());
            System.out.println("Usable space (bytes): " + root.getUsableSpace());
        }
    }
}
