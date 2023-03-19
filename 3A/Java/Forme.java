import java.util.Scanner;

//public class test{

//	public static void main(String[] args) {
//		System.out.println("Bonjour");
//	}
//}

public class Forme 
{	protected int x, y;
	private int couleur;

	public Forme(){
		Scanner sc = new Scanner(System.in);
		System.out.println("position en x:");
		x = sc.nextInt();
		System.out.println("position en y:");
		y = sc.nextInt();
		System.out.println("couleur de la forme:");
		couleur = sc.nextInt();
	}

	public void afficher()
	{
		System.out.println("Positon "+x+" , "+y);
		System.out.println("Couleur "+couleur);
	}

	public void dépalcer(int nx, int ny){
		x=nx;
		y=ny;
	}

	public static void main(String[] args) {
		Forme test = new Forme();
		test.afficher();
	}
}
