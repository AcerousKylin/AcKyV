package NeuEnter_Fall23.Aug_25.Chapter_7;

public class Code1 {
    
    public static class Football_Team
    {
        public static int number = 11;
        public void buildTeam()
        {
            while (this.number > 0)
            {
                Football_Member temp = new Football_Member();
                if (temp.equals(temp))
                    System.out.println("Hired a football member.");
            }
        }
    }

    public static class Football_Member extends Football_Team
    {
        public Football_Member()
        {
            super.number--;
        }
    }

    public static void main(String[] args)
    {
        Football_Team Barcelona = new Football_Team();
        Barcelona.buildTeam();
    }
}
