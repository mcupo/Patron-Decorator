#include <iostream>

using namespace std;

class ComponenteVisual

{

    public:

        virtual void Dibujar(){}

        virtual void CambiarTamano(){}

        //..

};

class VistaTexto : public ComponenteVisual

{

    public:

        virtual void Dibujar()

        {

            cout<<"Dibuja una VistaTexto.\n";

        }

        virtual void CambiarTamano(){}

};

class Ventana : public ComponenteVisual

{

    public:

        virtual void Dibujar(){}

        virtual void CambiarTamano(){}

        void EstablecerContenido(ComponenteVisual* contenido)

        {

            //..

        }

};

class Decorador : public ComponenteVisual

{

    private:

        ComponenteVisual* _componente;

    public:

        Decorador(ComponenteVisual*c)

        {

            _componente=c;

        }

        virtual void Dibujar()

        {

            _componente->Dibujar();

        }

        virtual void CambiarTamano()

        {

            _componente->CambiarTamano();

        }

        //..

};

class DecoradorBorde : public Decorador

{

    private:

        int _ancho;

        void DibujarBorde(int){cout<<"Decoro con un borde.\n";}

    public:

        DecoradorBorde(ComponenteVisual*c, int anchoBorde):Decorador(c){}

        void Dibujar()

        {

            Decorador::Dibujar();

            DibujarBorde(_ancho);

        }

};

class DecoradorSombra : public Decorador

{

    private:

        void DibujarSombra(){cout<<"Decoro con una sombra.\n";}

    public:

        DecoradorSombra(ComponenteVisual*c):Decorador(c){}

        void Dibujar()

        {

            Decorador::Dibujar();

            DibujarSombra();

        }

};

void main()

{

    ComponenteVisual* componenteDecorado = new DecoradorBorde(new DecoradorSombra(new VistaTexto),1);

    componenteDecorado->Dibujar();

    cin.get();

    delete componenteDecorado;

}
