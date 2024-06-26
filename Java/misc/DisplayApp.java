package misc;

import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Properties;
import java.util.stream.Collectors;

public class DisplayApp {

    public static void main(String[] args) {

        Properties properties = System.getProperties();

        // Thanks Java 8
        LinkedHashMap<String, String> collect = properties.entrySet().stream()
                .collect(Collectors.toMap(k -> (String) k.getKey(), e -> (String) e.getValue()))
                .entrySet().stream().sorted(Map.Entry.comparingByKey())
                .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue,
                        (oldValue, newValue) -> oldValue, LinkedHashMap::new));

        collect.forEach((k, v) -> System.out.println(k + ":" + v));

    }

}