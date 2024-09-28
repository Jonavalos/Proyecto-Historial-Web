#include "Control.h"

//este programa incluye bibliotecas: iostream, sstream, string, conio.h, algorithm, windows.h, ,fstream, vector, chrono, thread

int main() {
   Control::getInstance()->navegar();     //Guardar y leer de pestanas ya sirve 

   /* Pestana* pestana = new Pestana();
    pestana->leerSitiosDisponibles();
    pestana->asignarActual("firefox.com");
    pestana->asignarActual("google.com");
    pestana->asignarActual("firefox.com");

    Pestana* pestana2 = new Pestana();
    pestana2->asignarActual("yahoo.com");
    
    Sesion pantalla;
    pantalla.agregarPestanaActual(pestana);
    pantalla.agregarPestanaActual(pestana2);
    pantalla.navegarPestanas();*/
    //std::vector<SitioWeb*> sitios;

    //std::fstream strm("sitiosDispinibles.csv", std::ios::in);
    //if (strm.good() && strm.is_open()) {
    //    SitioWeb* aux;
    //    while ((aux = SitioWeb::recuperar(strm)) != nullptr) {
    //        sitios.push_back(aux);
    //    }
    //}
    //strm.close();

    //Pestana* pestana=new Pestana(nullptr, false, sitios);
    //pestana->asignarActual("firefox.com");
    //pestana->asignarActual("google.com");

    //std::fstream s("pruebaPestana.csv", std::ios::out);
    //if (s.good() && s.is_open()) {
    //    pestana->guardar(s);
    //    pestana->guardar(s);
    //}
    //s.close();
    //Pestana* pes2 = nullptr;
    //Pestana* pes3 = nullptr;
    //std::fstream leer("pruebaPestana.csv", std::ios::in);

    //if (leer.good() && leer.is_open()) {
    //     pes2 = Pestana::leer(leer, sitios);
    //     pes3 = Pestana::leer(leer, sitios);
    //}
    //leer.close();

    //pes3->getSitioActual()->setEtiqueta("Pop");
    //std::cout << pes3->imprimirActual();
    //std::cout << pes2->imprimirActual();
    //std::cout << pestana->imprimirActual();


    //if (pestana)
    //    delete pestana;
    //if (pes2)
    //    delete pes2;
   
   // std::vector<SitioWeb*> sitiosWeb;
   // SitioWeb* sit = nullptr;
   //


   // std::fstream guardar("sitiosDispinibles.csv",std::ios::in);
   // if (guardar.good() && guardar.is_open()) {
   //     for (int i = 0; i < 25; i++) {
   //         sit=SitioWeb::recuperar(guardar);
   //         sitiosWeb.push_back(sit);
   //     }
   //}
   //guardar.close();

   //int i = 0;
   //for (SitioWeb* s : sitiosWeb) {
   //    std::cout << "Pagina #" << i++ << "\n";
   //    std::cout << s->toString() << "\n\n";
   //}

   /* std::vector<std::string>* tags = new std::vector<std::string>();


   SitioWeb* sitio1 = new SitioWeb("Google", "google.com", "https://www.google.com", tags, false);
   SitioWeb* sitio2 = new SitioWeb("YouTube", "youtube.com", "https://www.youtube.com", tags, false);
   SitioWeb* sitio3 = new SitioWeb("Facebook", "facebook.com", "https://www.facebook.com", tags, false);
   SitioWeb* sitio4 = new SitioWeb("Amazon", "amazon.com", "https://www.amazon.com", tags, false);
   SitioWeb* sitio5 = new SitioWeb("Wikipedia", "wikipedia.org", "https://www.wikipedia.org", tags, false);
   SitioWeb* sitio6 = new SitioWeb("Twitter", "twitter.com", "https://www.twitter.com", tags, false);
   SitioWeb* sitio7 = new SitioWeb("Instagram", "instagram.com", "https://www.instagram.com", tags, false);
   SitioWeb* sitio8 = new SitioWeb("LinkedIn", "linkedin.com", "https://www.linkedin.com", tags, false);
   SitioWeb* sitio9 = new SitioWeb("Netflix", "netflix.com", "https://www.netflix.com", tags, false);
   SitioWeb* sitio10 = new SitioWeb("Reddit", "reddit.com", "https://www.reddit.com", tags, false);

   SitioWeb* sitio11 = new SitioWeb("Pinterest", "pinterest.com", "https://www.pinterest.com", tags, false);
   SitioWeb* sitio12 = new SitioWeb("Quora", "quora.com", "https://www.quora.com", tags, false);
   SitioWeb* sitio13 = new SitioWeb("Dropbox", "dropbox.com", "https://www.dropbox.com", tags, false);
   SitioWeb* sitio14 = new SitioWeb("GitHub", "github.com", "https://www.github.com", tags, false);
   SitioWeb* sitio15 = new SitioWeb("Slack", "slack.com", "https://www.slack.com", tags, false);
   SitioWeb* sitio16 = new SitioWeb("Zoom", "zoom.us", "https://www.zoom.us", tags, false);
   SitioWeb* sitio17 = new SitioWeb("Spotify", "spotify.com", "https://www.spotify.com", tags, false);
   SitioWeb* sitio18 = new SitioWeb("Twitch", "twitch.tv", "https://www.twitch.tv", tags, false);
   SitioWeb* sitio19 = new SitioWeb("Microsoft", "microsoft.com", "https://www.microsoft.com", tags, false);
   SitioWeb* sitio20 = new SitioWeb("Apple", "apple.com", "https://www.apple.com", tags, false);

   SitioWeb* sitio21 = new SitioWeb("Adobe", "adobe.com", "https://www.adobe.com", tags, false);
   SitioWeb* sitio22 = new SitioWeb("Stack Overflow", "stackoverflow.com", "https://www.stackoverflow.com", tags, false);
   SitioWeb* sitio23 = new SitioWeb("Coursera", "coursera.org", "https://www.coursera.org", tags, false);
   SitioWeb* sitio24 = new SitioWeb("Udemy", "udemy.com", "https://www.udemy.com", tags, false);
   SitioWeb* sitio25 = new SitioWeb("Khan Academy", "khanacademy.org", "https://www.khanacademy.org", tags, false);


   std::vector<SitioWeb*> sitiosWeb;
   sitiosWeb.push_back(sitio1);
   sitiosWeb.push_back(sitio2);
   sitiosWeb.push_back(sitio3);
   sitiosWeb.push_back(sitio4);
   sitiosWeb.push_back(sitio5);
   sitiosWeb.push_back(sitio6);
   sitiosWeb.push_back(sitio7);
   sitiosWeb.push_back(sitio8);
   sitiosWeb.push_back(sitio9);
   sitiosWeb.push_back(sitio10);

   sitiosWeb.push_back(sitio11);
   sitiosWeb.push_back(sitio12);
   sitiosWeb.push_back(sitio13);
   sitiosWeb.push_back(sitio14);
   sitiosWeb.push_back(sitio15);
   sitiosWeb.push_back(sitio16);
   sitiosWeb.push_back(sitio17);
   sitiosWeb.push_back(sitio18);
   sitiosWeb.push_back(sitio19);
   sitiosWeb.push_back(sitio20);

   sitiosWeb.push_back(sitio21);
   sitiosWeb.push_back(sitio22);
   sitiosWeb.push_back(sitio23);
   sitiosWeb.push_back(sitio24);
   sitiosWeb.push_back(sitio25);

    std::fstream guarda("sitiosDispinibles.csv",std::ios::out);
   if (guarda.good() && guarda.is_open()) {
       for (SitioWeb* s:sitiosWeb) {
           s->guardar(guarda);
       }
  }
  guarda.close();*/

//   std::vector<SitioWeb*> sitiosLeidos;
//    SitioWeb* sit = nullptr;
//   
//
//
//    std::fstream guardar("sitiosDispinibles.csv",std::ios::in);
//    if (guardar.good() && guardar.is_open()) {
//        for (int i = 0; i < 25; i++) {
//            sit=SitioWeb::recuperar(guardar);
//            sitiosLeidos.push_back(sit);
//        }
//   }
//   guardar.close();
//
//   Pestana* pes = new Pestana(nullptr,false,sitiosLeidos);
//
//   pes->asignarActual(sitiosLeidos.at(0)->getUrl());
//
//   std::fstream guarda("prueba.csv", std::ios::out);
//   if (guarda.good() && guarda.is_open()) {
//       pes->guardar(guarda);
//   }
//   guarda.close();
//
//   Pestana* pes2 = nullptr;
//   std::fstream guard("prueba.csv", std::ios::in);
//   if (guard.good() && guard.is_open()) {
//       pes2 = Pestana::leer(guard,sitiosLeidos);
//   }
//   guard.close();
//
//   pes2->setSitiosDisponibles(sitiosLeidos);
//  
//std::cout<<pes2->imprimirActual();

//Sesion* ses = new Sesion("Josue");
//ses->agregarPestanaActual(new Pestana(nullptr, false, ses->getSitios()));
//Sesion* se = nullptr;
//
//std::fstream guardar("sesionPrueba.dat", std::ios::out | std::ios::binary);
//    if (guardar.good() && guardar.is_open()) {
//        ses->guardar(guardar);
//   }
//   guardar.close();
//
//   std::fstream g("sesionPrueba.dat", std::ios::in | std::ios::binary);
//   if (g.good() && g.is_open()) {
//       se = Sesion::leer(g);
//   }
//   g.close();




    return 0;

}

/*
To do (para hacer)

agregarPestanaActual() en menu
guardar sesion 
limitar tamano del historial
vector de sitios marcados (bookmark)

*/