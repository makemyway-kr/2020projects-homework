import java.util.Arrays;
import java.util.Scanner;
class seat
{
	
	String [] S={"---","---","---","---","---","---","---","---","---","---"};
	String [] A={"---","---","---","---","---","---","---","---","---","---"};
	String [] B={"---","---","---","---","---","---","---","---","---","---"};
	
	
}
class module
{
	Scanner s=new Scanner(System.in);
	seat seats=new seat();
	public void book()
	{
		int snumber;
		String name;
		System.out.println("�¼����� S(1), A(2), B(3)>> ");
		int select1=s.nextInt();
		if(select1>3)//����ó��
		{
			System.out.print("�߸��Է��ϼ̽��ϴ�");
			select1=s.nextInt();
		}
		else
		{
			switch(select1)
			{
			case 1:
				System.out.println(Arrays.toString(seats.S));
				System.out.print("�̸�>>");
				name=s.next();
				System.out.print("��ȣ>>");
				snumber=s.nextInt();
				if(snumber>10)//����ó��
				{
					System.out.println("���� �¼� ��ȣ�Դϴ�.");
					
				}
				else 
				{
					if(seats.S[snumber-1].equals("---")) 
					{
						seats.S[snumber-1]=name;
						break;
					}
					else 
						{
						     System.out.println("�̹� ����� �¼��Դϴ�.");
						     break;
						}
					
				}
				
			case 2:
				System.out.println(Arrays.toString(seats.A));
				System.out.print("�̸�>>");
				name=s.next();
				System.out.print("��ȣ>>");
			    snumber=s.nextInt();
			    if(snumber>10) //����ó��
				{
					System.out.println("���� �¼� ��ȣ�Դϴ�.");
					
				}
			    else 
				{
					if(seats.A[snumber-1].equals("---")) 
					{
						seats.A[snumber-1]=name;
						break;
					}
					else 
						{
						     System.out.println("�̹� ����� �¼��Դϴ�.");
						     break;
						}
					
				}
				
			case 3:
				System.out.println(Arrays.toString(seats.B));
				System.out.print("�̸�>>");
				name=s.next();
				System.out.print("��ȣ>>");
			    snumber=s.nextInt();
			 
			    if(snumber>10) //����ó��
				{
					System.out.println("���� �¼� ��ȣ�Դϴ�.");
					
				}
			    else 
				{
					if(seats.B[snumber-1].equals("---")) 
					{
						seats.B[snumber-1]=name;
						break;
					}
					else 
						{
						     System.out.println("�̹� ����� �¼��Դϴ�.");
						     break;
						}
					
				}
			
			}
		}
		
	}
	public void reference()
	{
		System.out.println("S>>"+Arrays.toString(seats.S));
		System.out.println("A>>"+Arrays.toString(seats.A));
		System.out.println("B>>"+Arrays.toString(seats.B));
		System.out.println("<<<<<��ȸ�� �Ϸ��Ͽ����ϴ�>>>>>");
	}
	public void cancel()
	{
		String name;
		int count=0;//����ó����
		System.out.println("�¼�: S(1), A(2), B(3)>> ");
		int select1=s.nextInt();
		if(select1>3)
		{
			System.out.println("�߸� �Է��ϼ̽��ϴ�.");
			select1=s.nextInt();
			
		}
		else
		{
			switch(select1)
			{
			case 1:
				System.out.println(Arrays.toString(seats.S));
				System.out.print("�̸�>>");
				name=s.next();
				
				for(int i=0;i<10;i++)
				{
					if(seats.S[i].equals(name))
					{
						seats.S[i]="---";
						count++;
					}
						
				}
				if(count==0)
				{
					System.out.println("ã���ô� �̸��� �������� �ʽ��ϴ�.");
				}
				break;
			case 2:
				
				System.out.println(Arrays.toString(seats.A));
				System.out.print("�̸�>>");
				name=s.next();
				for(int i=0;i<10;i++)
				{
					if(seats.A[i].equals(name))
					{
						seats.A[i]="---";
						count++;
					}
						
				}
				if(count==0)
				{
					System.out.println("ã���ô� �̸��� �������� �ʽ��ϴ�.");
				}
				break;
			case 3:
				System.out.println(Arrays.toString(seats.B));
				System.out.print("�̸�>>");
				name=s.next();
				for(int i=0;i<10;i++)
				{
					if(seats.B[i].equals(name))
					{
						seats.B[i]="---";
						count++;
					}
						
				}
				if(count==0)
				{
					System.out.println("ã���ô� �̸��� �������� �ʽ��ϴ�.");
				}
				break;
			}
		}
		
	}
	
	
}
	
class bookingSystem
{
	Scanner sc=new Scanner(System.in);
	module m=new module();
	bookingSystem()
	{
	    System.out.println("��ǰ�ܼ�ƮȦ ����ý����Դϴ�.");
	}
	public void main_System()
	{
		while(true)
		{
			System.out.print("1.���� 2.��ȸ 3.��� 4.������>>");
			int select=sc.nextInt();
			if(select==1)
			{
				m.book();
			}
			else if(select==2)
			{
				m.reference();
			}
			else if(select==3)
			{
				m.cancel();
			}
			else if(select==4)
			{
				break;
			}
			else System.out.println("�߸� �Է��ϼ̽��ϴ�.");//���¸޴� ����ó��
		}
			
	}
	
}

public class Number12 {

	public static void main(String[] args) {
		bookingSystem bs=new bookingSystem();
		bs.main_System();

	}

}
