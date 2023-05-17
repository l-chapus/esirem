public class Cercle extends FormeGeometrique {
	
	protected double rayon;

	public Cercle (double epaisseurTrait ,double rayon){
		super(epaisseurTrait);
		this.rayon = rayon;
	}

	public double getRayon () {
		return this.rayon;
	}
	public double calculPerimetre(){
		double S=0.0;
		S = 2 * 3.14 * this.rayon;
		return S;
	}

	public double calculSuperficie(){
		double S=0;
		S = 3.14 * this.rayon * this.rayon;
		return S;
	}
	public String toString(){
		String info;
		info = "Périmètre du cercle : " + this.calculPerimetre() + "\nSuperficie du cercle : " + this.calculSuperficie();
		return info;
	}
	
}