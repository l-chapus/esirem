public class Personne {
	protected String nom ;
	protected String prenom ;
	protected int age ;
	
	public Personne (){
		nom = "";
		prenom = "";
		age = -1;
	}
	public Personne ( String nom , String prenom , int age ){
		this . nom = nom ;
		this . prenom = prenom ;
		this . age = age ;
	}

	public String getNom () {
		return this.nom;
	}
	public String getPrenom () {
		return this.prenom;
	}
	public int getAge () {
		return this.age;
	}
	public void setNom( String nom) {
		this.nom = nom;
	}
	public void setPrenom( String prenom) {
		this.prenom = prenom;
	}
	public void setAge ( int age) {
		this.age = age;
	}

	public void ouMeTrouver(){
		System.out.println("Je ne sais pas où je suis.");
	}

	public String toString(){
		String info = nom + " " + prenom + " a " + age + " ans.";
		return info;
	}
}