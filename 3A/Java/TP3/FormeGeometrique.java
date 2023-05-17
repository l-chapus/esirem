public abstract class FormeGeometrique {

	protected double epaisseurTrait;

	public FormeGeometrique(double epaisseurTrait){
		this.epaisseurTrait = epaisseurTrait;
	}

	public abstract double calculPerimetre();
	public abstract double calculSuperficie();
	public abstract String toString();
	
}