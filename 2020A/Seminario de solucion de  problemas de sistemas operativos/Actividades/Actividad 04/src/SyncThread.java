import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

public class SyncThread implements Runnable {

    private AtomicBoolean keepRunning = new AtomicBoolean(true);
    private AtomicBoolean pause = new AtomicBoolean(false);

    private ReentrantLock lckPause = new ReentrantLock();
    private Condition conPause = lckPause.newCondition();
    private int number = 0;

    public SyncThread(int maxTime) {
		number = maxTime;
	}

	public void run() {
        while (keepRunning.get() && !Thread.currentThread().isInterrupted()) {
            while (pause.get() && !Thread.currentThread().isInterrupted()) {
                lckPause.lock();
                try {
                    System.out.println("Paused");
                    conPause.await();
                } catch (InterruptedException ex) {
                    ex.printStackTrace();
                } finally {
                    lckPause.unlock();
                }
            }
            if (!Thread.currentThread().isInterrupted()) {
            	if(number >= 0) {
            		try {
						System.out.print("    " + number);
						Thread.sleep(1000);
						number--;
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
            	}
            }
        }
    }

    public void setPaused(boolean paused) {
        if (pause.get() != paused) {
            pause.set(paused);
            if (!paused) {
                lckPause.lock();
                try {
                    conPause.signal();
                } finally {
                    lckPause.unlock();
                }
            }
        }
    }

    public void terminate() {
        keepRunning.set(false);
        setPaused(false);
    }

}