class Main
{
	public static void main(String[] args) {
		Cercle forme1 = new Cercle(1.0,5);
		Rectangle forme2 = new Rectangle(1.0,5,9);
		
		System.out.println(forme1.toString());
		System.out.println(forme2.toString());

		TableauFormeGeometrique tab1 = new TableauFormeGeometrique(5);
		tab1.ajouterForme(forme1);
		tab1.ajouterForme(forme2);

		System.out.println(tab1.toString());
	}
}
