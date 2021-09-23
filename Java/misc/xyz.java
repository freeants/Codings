package misc;

class xyz {
    public static void main(String[] args) {
        for (int x = 0; x < 10; x++)
            for (int y = 0; y < 10; y++)
                for (int z = 0; z < 10; z++)
                    if ((x + y) == 9 && (y + z) == 12 && (x + z) == 15)
                        System.out.printf("%d, %d, %d\n", x, y, z);
    }
}
