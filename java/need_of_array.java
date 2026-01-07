public class need_of_array {

    public static void main(String[] args) {
        // Array to store marks of 5 subjects
        int[] marks = new int[5];

        // Assigning values to the array
        marks[0] = 85;
        marks[1] = 90;
        marks[2] = 78;
        marks[3] = 92;
        marks[4] = 88;

        // Calculating total marks
        int total = 0;
        for (int i = 0; i < marks.length; i++) {
            total += marks[i];
        }

        // Calculating average marks
        double average = total / (double) marks.length;

        // Displaying the results
        System.out.println("Total Marks: " + total);
        System.out.println("Average Marks: " + average);
    }
}