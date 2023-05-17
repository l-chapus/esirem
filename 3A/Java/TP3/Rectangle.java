public class Rectangle extends FormeGeometrique {
	
	protected double longueur;
	protected double largeur;
	
	public Rectangle (double epaisseurTrait ,double longueur ,double largeur ){
		super(epaisseurTrait);
		this.longueur = longueur;
		this.largeur = largeur;
	}

	public double getLongueur () {
		return this.longueur;
	}
	public double getLargeur () {
		return this.largeur;
	}

	public double calculPerimetre(){
		double S=0;
		S = 2*this.largeur + 2*this.longueur;
		return S;
	}

	public double calculSuperficie(){
		double S=0;
		S = this.largeur * this.longueur;
		return S;
	}

	public String toString(){
		String info;
		info = "\nPérimètre du rectangle : " + this.calculPerimetre() + "\nSuperficie du rectangle : " + this.calculSuperficie();
		return info;
	}

	
}