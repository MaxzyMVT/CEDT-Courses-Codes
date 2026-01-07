package Test01;

public class CommandLineArgument {

    private static int ans;

    public static void main(String[] args) {

        int input, ans;

        try {
            input = Integer.parseInt(args[0]);
        } catch (Exception e) {
            System.out.println("! Input Error !");
            throw new RuntimeException(e);
        }

        if(input >= -10 && input <= -5) {
            ans = -(input * input);
        } else if (input > -5 && input <= 0 || input > 5 && input <= 10) {
            ans = 0;
        } else if (input > 0 && input <= 10) {
            ans = input * input;
        } else {
            ans = input * input * input;
        }

        System.out.println("The Answer is: " + ans);
    }
}
