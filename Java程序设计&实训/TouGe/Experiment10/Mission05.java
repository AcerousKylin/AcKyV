package TouGe.Experiment10;

public class Mission05 {
    public static void main(String[] args) {
     
        int[] scores={79,52,98,81};
		/********** Begin **********/
        //调用方法，传入成绩数组，并获取成绩的个数
        int count= sort(scores);
		/********** End **********/
        System.out.println("共有"+count+"个成绩信息！");
    }

    /*
     * 功能：将考试成绩排序并输出，返回成绩的个数
     * 
     */
	/********** Begin **********/	
    public static int sort(int[] arr ){
       // 数组从小到大排序处理
        for (int i=3; i>=0; i--)
        {
            for (int j=0; j<i; j++)
            {
                if (arr[j] > arr[j+1])
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
       // 打印出数组
       System.out.print("[");
        for (int i=0; i<4; i++)
        {
            System.out.print(arr[i]);
            if (i < 3)
                System.out.print(", ");
        }
        System.out.println("]");
       //返回数组中元素的个数
        return arr.length;
    }
	/********** End **********/
}
