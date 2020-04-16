import java.util.Comparator;
import java.util.PriorityQueue;

public class Solution{
    PriorityQueue<Integer> minHeap = new PriorityQueue<>();
    PriorityQueue<Integer> maxHeap = new PriorityQueue<>(new Comparator<Integer>() {
        public int compare(Integer o1,Integer o2){
            return o2-o1;
        }
    });
    int count = 0;
    public void Insert(Integer num){
        if(count%2==0){
            maxHeap.offer(num);
            //保证大顶里面所有都小于小顶，所以把大顶最大插入到小顶
            int max = maxHeap.poll();
            minHeap.offer(max);
        }else{
            minHeap.offer(num);
            int min = minHeap.poll();
            maxHeap.offer(min);
        }
        count++;

    }
    public Double GetMedian(){
        if(count%2==0){
            return (minHeap.peek()+maxHeap.peek())/2.0;
        }else{
            return new Double(minHeap.peek());
        }

    }
    public static void main(String[] args) {
        Solution s = new Solution();
        s.Insert(2);
        s.Insert(3);
        s.Insert(5);
    }
}