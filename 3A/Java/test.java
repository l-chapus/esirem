public class test{

	public static void main(String[] args) {
		System.out.println("Bonjour");
	}
}

public class Forme 
{	protected int x, y;
	private int couleur;

	public Forme(){
		System.out.println("position en x:");
		x=1;
		System.out.println("position en y:");
		y=3;
		System.out.println("couleur de la forme:");
		couleur=4;
	}

	public void afficher()
	{
		System.out.println("positon"+x+","+y);
		System.out.println("couleur"+couleur);
	}

	public void dépalcer(int nx, int ny){
		x=nx;
		y=ny;
	}
}
