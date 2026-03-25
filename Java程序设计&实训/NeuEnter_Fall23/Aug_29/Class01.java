package NeuEnter_Fall23.Aug_29;

public class Class01 {
    public static void main(String[] args)
    {
        Inheriter Inhe1 = new Inheriter();
        // Inheriter Inhe2 = new Inheriter();
    }

    public static class Ancester
    {
        static int varA1 = 1;
        int varA2 = getVarA3();
        int varA3 = 3;
        int getVarA3()
        {
            return varA3;
        }

        static
        {
            // System.out.println(varA1);
            System.out.println("Ancester's static code has run.");
        }

        {
            // System.out.println(varA3);
            // System.out.println(varA1);
            System.out.println("Ancester's common code has run.");
        }

        public Ancester()
        {
            System.out.println("Ancester's construct code has run.");
        }
    }

    public static class Inheriter extends Ancester
    {
        int varA3 = getInheA();
        int getVarA3()
        {
            return varA3;
        }
        int getInheA()
        {
            return varA4;
        }
        int varA4 = 4;

        public Inheriter()
        {
            // System.out.println(varA3);
            // System.out.println(varA2);
            // System.out.println(varA4);
            System.out.println("Inheriter's construct code has run.");
        }

        static
        {
            // System.out.println(varA1);
            System.out.println("Inheriter's static code has run.");
        }

        {
            // System.out.println(varA3);
            // System.out.println(varA1);
            System.out.println("Inheriter's common code has run.");  
        }
    }
}

/*
1
Ancester's static code has run.    
1
Inheriter's static code has run.   
3
1
Ancester's common code has run.    
Ancester's construct code has run. 
0
1
Inheriter's common code has run.   
0
0
4
Inheriter's construct code has run.
3
1
Ancester's common code has run.
Ancester's construct code has run.
0
1
Inheriter's common code has run.
0
0
4
Inheriter's construct code has run.
*/