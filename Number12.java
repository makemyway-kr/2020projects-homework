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
		System.out.println("좌석구분 S(1), A(2), B(3)>> ");
		int select1=s.nextInt();
		if(select1>3)//예외처리
		{
			System.out.print("잘못입력하셨습니다");
			select1=s.nextInt();
		}
		else
		{
			switch(select1)
			{
			case 1:
				System.out.println(Arrays.toString(seats.S));
				System.out.print("이름>>");
				name=s.next();
				System.out.print("번호>>");
				snumber=s.nextInt();
				if(snumber>10)//예외처리
				{
					System.out.println("없는 좌석 번호입니다.");
					
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
						     System.out.println("이미 예약된 좌석입니다.");
						     break;
						}
					
				}
				
			case 2:
				System.out.println(Arrays.toString(seats.A));
				System.out.print("이름>>");
				name=s.next();
				System.out.print("번호>>");
			    snumber=s.nextInt();
			    if(snumber>10) //예외처리
				{
					System.out.println("없는 좌석 번호입니다.");
					
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
						     System.out.println("이미 예약된 좌석입니다.");
						     break;
						}
					
				}
				
			case 3:
				System.out.println(Arrays.toString(seats.B));
				System.out.print("이름>>");
				name=s.next();
				System.out.print("번호>>");
			    snumber=s.nextInt();
			 
			    if(snumber>10) //예외처리
				{
					System.out.println("없는 좌석 번호입니다.");
					
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
						     System.out.println("이미 예약된 좌석입니다.");
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
		System.out.println("<<<<<조회를 완료하였습니다>>>>>");
	}
	public void cancel()
	{
		String name;
		int count=0;//예외처리용
		System.out.println("좌석: S(1), A(2), B(3)>> ");
		int select1=s.nextInt();
		if(select1>3)
		{
			System.out.println("잘못 입력하셨습니다.");
			select1=s.nextInt();
			
		}
		else
		{
			switch(select1)
			{
			case 1:
				System.out.println(Arrays.toString(seats.S));
				System.out.print("이름>>");
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
					System.out.println("찾으시는 이름이 존재하지 않습니다.");
				}
				break;
			case 2:
				
				System.out.println(Arrays.toString(seats.A));
				System.out.print("이름>>");
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
					System.out.println("찾으시는 이름이 존재하지 않습니다.");
				}
				break;
			case 3:
				System.out.println(Arrays.toString(seats.B));
				System.out.print("이름>>");
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
					System.out.println("찾으시는 이름이 존재하지 않습니다.");
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
	    System.out.println("명품콘서트홀 예약시스템입니다.");
	}
	public void main_System()
	{
		while(true)
		{
			System.out.print("1.예약 2.조회 3.취소 4.끝내기>>");
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
			else System.out.println("잘못 입력하셨습니다.");//없는메뉴 예외처리
		}
			
	}
	
}

public class Number12 {

	public static void main(String[] args) {
		bookingSystem bs=new bookingSystem();
		bs.main_System();

	}

}
