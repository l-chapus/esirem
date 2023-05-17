class TableauFormeGeometrique {

    protected int nbFormeGeometrique;
    protected FormeGeometrique tabFormeGeometrique[];

    public TableauFormeGeometrique(int nbFormeGeometrique){
        this.nbFormeGeometrique = nbFormeGeometrique;
        this.tabFormeGeometrique = new FormeGeometrique[nbFormeGeometrique];
    }

    public void ajouterForme(FormeGeometrique forme){
        for(int k=0; k<nbFormeGeometrique;k++){
            if(this.tabFormeGeometrique[k] == null){
                this.tabFormeGeometrique[k]=forme;
                break;
            }
        }
    }

    public String toString(){
        String info="";
        for(int k=0 ; k<nbFormeGeometrique ; k++){
            if(this.tabFormeGeometrique[k] != null){
                info = info + this.tabFormeGeometrique[k].toString();
            }
        }
        return info;
    }
}