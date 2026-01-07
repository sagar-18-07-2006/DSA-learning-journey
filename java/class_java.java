 class calc {
    int a ;
    
    public int add(int n1,int n2)
    {   System.out.println("Added numbers");
        return n1+n2;
    }
    public int add(int n1,int n2, int n3)
    {   System.out.println("Added numbers");
        return n1+n2+n3;
    }
}

public class class_java {
    int data =10;
    public static void main(String[] args) {int num1 =2,num2 =4;
    calc a =new calc();
    int result = a.add(num2, num1);
    System.out.println(result);}
    
}
    