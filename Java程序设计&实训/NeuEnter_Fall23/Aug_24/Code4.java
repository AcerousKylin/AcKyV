package NeuEnter_Fall23.Aug_24;

public class Code4 {
    public static void main(String[] args)
    {
        int[][] a={ {2, 3, 4}, {4, 6, 8}}, b={{1, 5, 2, 8}, {5, 9, 10, -3}, {2, 7, -5, -18}};
        int[][] result = new int[2][4];
        for (int i=0; i<2; i++)
            for (int j=0; j<4; j++)
                for (int k=0; k<3; k++)
                    result[i][j] += a[i][k] * b[k][j];
        for (int i=0; i<2; i++)
        {
            for (int j=0; j<4; j++)
                System.out.printf("%5d",result[i][j]);
            System.out.println("");
        }
    }
}
