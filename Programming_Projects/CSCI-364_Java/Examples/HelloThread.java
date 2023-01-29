public class HelloThread extends Thread {
    
    private int val;

    public HelloThread (int val){
        this.val = val;
    }

    public void run (){
        System.out.println("Hello from thread " + this.getName() + ". My val is " + this.val);
    }

    public static void main (String[] args){
        for (int i = 0; i < 5; i++){
            HelloThread hello = new HelloThread(i);
            hello.start();

            try {
                // What happens when the join is commented out??
                hello.join();
            } catch (Exception e){
                System.out.println("interrupted");
            }
        }
    }
}
