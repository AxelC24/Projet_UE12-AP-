#include <iostream>
#include <string>
#include <memory>
#include <limits>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Arme{
public:
    int degat_;
    std::string name_;
    Arme(std::string name,int degats):name_(name),degat_(degats){}
    std::string Name(){return name_;}
    int Degats(){return degat_;}
    void afficherInfos() {
        std::cout << "Nom : " << name_ << std::endl;
        std::cout << "Degats : " << degat_ << std::endl;
    }
};

class Epee_simple : public Arme{
    public:
    Epee_simple():Arme("Epee simple",35){}
};
class Hache_simple: public Arme{
    public:
    Hache_simple():Arme("Hache simple",40){}
};

class Hache_deux_mains: public Arme{
    public:
    Hache_deux_mains():Arme("Hache à deux mains",70){}
};

class Epee_deux_mains: public Arme{
    public:
    Epee_deux_mains():Arme("Epee à deux mains",60){}
};
class Baguette_magique: public Arme{
    public:
    Baguette_magique():Arme("Baguette magique",55){}
    
};
class Arc: public Arme{
    public:
    Arc():Arme("Arc",50){}
};
class Hallebarde : public Arme {
public:
    Hallebarde() : Arme("Hallebarde", 60) {}
};

class Marteau : public Arme {
public:
    Marteau() : Arme("Marteau", 65) {}
};

class Lance : public Arme {
public:
    Lance() : Arme("Lance", 45) {}
};

class Armure {
public:
    int protec_;
    std::string name_;
    Armure(std::string name,int protection):name_(name),protec_(protection){}
    std::string Name(){return name_;}
    int Protection(){return protec_;}
    void Infos() {
        std::cout << "Nom : " << name_ << std::endl;
        std::cout << "Protection : " << protec_ << std::endl;
    }
};

class Armure_basique : public Armure{
    public:
    Armure_basique():Armure("Armure basique",20){}
};
class Armure_renforcee: public Armure{
    public:
    Armure_renforcee():Armure("Armure renforcee",40){}
};

class Armure_evoluee: public Armure{
    public:
    Armure_evoluee():Armure("Armure evoluee",60){}
};

class Personnage {
public:
    std::string nom;
    int pointsDeVie;
    int force;
    int dexterite;
    int vitesse;
    int intelligence;
    std::shared_ptr<Arme> arme_;
    std::shared_ptr<Armure> armure_;

public:
    Personnage(const std::string& _nom, int _pointsDeVie, int _force, int _dexterite, int _vitesse, int _intelligence) : nom(_nom), pointsDeVie(_pointsDeVie), force(_force), dexterite(_dexterite), vitesse(_vitesse), intelligence(_intelligence) {}
    void attaquer(std::shared_ptr<Personnage> cible)
    {
        int degats = (force + dexterite + intelligence + vitesse) / 4 + arme_->Degats();
        std::cout << nom << " attaque " << cible->nom << " avec son " << arme_->Name() << " et lui inflige " << degats << " dégats" << std::endl;
        cible->pointsDeVie -= degats;
    }
    virtual void afficher() const {
        std::cout << "Nom: " << nom << ", Points de vie: " << getPointsDeVie() << ", Force: " << force << ", Dextérité: " << dexterite << ", Vitesse: " << vitesse << ", Intelligence: " << intelligence << std::endl;
    }

    bool Alive() { return pointsDeVie > 0; }
    void printName() { std::cout << nom << std::endl; }
    void printArme() { std::cout << arme_->Name() << std::endl; }

    void setArme(std::shared_ptr<Arme> arme) { arme_ = arme; }
    void setArmure(std::shared_ptr<Armure> armure) { armure_ = armure; }

    void Soins(int combien) {
        pointsDeVie += combien;
        }
    std::string getNom() const { return nom; }
    int getPointsDeVie() const {
    if (armure_ != nullptr) {
        return pointsDeVie + armure_->Protection();
    } 
    else {
        return pointsDeVie;
    }
}
};


class Guerrier : public Personnage {
public:
    Guerrier(const std::string& _nom) : Personnage(_nom, 150, 16, 8, 9, 5) {}
};
class Mage : public Personnage {
public:
    Mage(const std::string& _nom) : Personnage(_nom, 100, 5, 10, 8, 15) {}
};
class Archer : public Personnage {
public:
    Archer(const std::string& _nom) : Personnage(_nom, 80, 8, 15, 15, 9) {}
};
class Voleur : public Personnage {
public:
    Voleur(const std::string& _nom) : Personnage(_nom, 90, 11, 18, 20, 9) {}
};
class Paladin : public Personnage {
public:
    Paladin(const std::string& _nom) : Personnage(_nom, 130, 13, 12, 8, 12) {}
};
class Barbare : public Personnage {
public:
    Barbare(const std::string& _nom) : Personnage(_nom, 180, 20, 5, 5, 5) {}
};
class Assassin : public Personnage {
public:
    Assassin(const std::string& _nom) : Personnage(_nom, 90, 12, 17, 20, 12) {}
};
class Invocateur : public Personnage {
public:
    Invocateur(const std::string& _nom) : Personnage(_nom, 110, 11, 14, 10, 20) {}
};

std::unique_ptr<Personnage> choisirClasse(const std::string& nom, int choix) {
    switch (choix) {
    case 1:
        return std::make_unique<Guerrier>(nom);
    case 2:
        return std::make_unique<Mage>(nom);
    case 3:
        return std::make_unique<Archer>(nom);
    case 4:
        return std::make_unique<Voleur>(nom);
    case 5:
        return std::make_unique<Paladin>(nom);
    case 6:
        return std::make_unique<Barbare>(nom);
    case 7:
        return std::make_unique<Assassin>(nom);
    case 8:
        return std::make_unique<Invocateur>(nom);
    default:
        std::cout << "Classe non reconnue, veuillez choisir à nouveau." << std::endl;
        return nullptr;
    }
}

class Quete {
public:
    string description;
    function<void(shared_ptr<Personnage>)> dialogue; 
    shared_ptr<Personnage> joueur;
    bool Terminee;

    Quete(string description, function<void(shared_ptr<Personnage>)> dialogue,shared_ptr<Personnage> joueur) :
        description(description),
        dialogue(dialogue),
        joueur(joueur),
        Terminee(false) {}

    void terminer() {
        Terminee = true;
        }
    void executer() {
        if (!Terminee) {
            dialogue(joueur);
            terminer();
        }}
};

std::shared_ptr<Arme> obtenirArmeAleatoire() {
    std::srand(std::time(nullptr));
    const int nombreTotalArmes = 9;
    int choix = (std::rand() % nombreTotalArmes) + 1;
    switch (choix) {
        case 1:
            return std::make_shared<Epee_simple>();
        case 2:
            return std::make_shared<Hache_simple>();
        case 3:
            return std::make_shared<Hache_deux_mains>();
        case 4:
            return std::make_shared<Epee_deux_mains>();
        case 5:
            return std::make_shared<Baguette_magique>();
        case 6:
            return std::make_shared<Arc>();
        case 7:
            return std::make_shared<Hallebarde>();
        case 8:
            return std::make_shared<Marteau>();
        case 9:
            return std::make_shared<Lance>();
        default:
            std::cerr << "Erreur : Arme non reconnue." << std::endl;
            return nullptr;
}
}

std::shared_ptr<Armure> obtenirArmureAleatoire() {
    std::srand(std::time(nullptr));
    const int nombreTotalArmures = 3;
    int choix = (std::rand() % nombreTotalArmures) + 1;
    switch (choix) {
        case 1:
            return std::make_shared<Armure_basique>();
        case 2:
            return std::make_shared<Armure_renforcee>();
        case 3:
            return std::make_shared<Armure_evoluee>();
        default:
            std::cerr << "Erreur : Armure non reconnue." << std::endl;
            return nullptr;
}
}

void Carriere_mystique(std::shared_ptr<Personnage> joueur) {

    
    std::cout << "Bienvenue, aventurier " << joueur->getNom() << "! Vous êtes sur la piste d'une créature légendaire connue sous le nom de Golem de fer." << std::endl;
    std::cout << "Vous explorez une région montagneuse reculée, où se trouve une carrière souterraine abandonnée, supposée être la demeure du Golem." << std::endl;
    std::cout << "Que décidez-vous de faire ?" << std::endl;
    std::cout << "1. Tenter de recueillir des informations auprès des habitants des villages avoisinants." << std::endl;
    std::cout << "2. Partir immédiatement à la recherche du Golem dans la carrière abandonnée." << std::endl;

    auto golem = std::make_shared<Personnage>("Golem", 120, 11, 8, 4, 4);
    golem->setArme(std::make_shared<Arme>("Masse", 35));

    if (!joueur->arme_) {
    joueur->setArme(std::make_shared<Arme>("Vieille epee emoussee", 15));
        }

    int choix;
    std::cin >> choix;
    switch (choix) {
        case 1:
            std::cout << "Vous choisissez de demander de l'aide aux villageois des environs, qui sont eclins à vous aider." << std::endl;
            std::cout << "Après avoir interrogé plusieurs villageois, vous apprenez que le Golem a été aperçu près de la carrière il y a quelques jours." << std::endl;
            std::cout << "Vous décidez donc de vous rendre immédiatement à la carrière abandonnée pour retrouver le golem." << std::endl;
            break;
        case 2:
            std::cout << "Vous décidez de vous aventurer directement dans la carrière à la recherche du Golem." << std::endl;
            std::cout << "Vous vous préparez mentalement au combat qui vous attend et pénétrez dans l'obscurité du lieu, qui vous parait menacant." << std::endl;
            std::cout << "Au bout de quelques heures de recherche, vous parvenez à repérer la silhouette massive du Golem au loin." << std::endl;
            std::cout << "Préparez-vous au combat !" << std::endl;

            while (joueur->Alive() && golem->Alive()) {
                joueur->attaquer(golem);
                if (golem->Alive()) {
                    golem->attaquer(joueur);
                }
            }

            if (!joueur->Alive()) {
                std::cout << "Malheureusement, le Golem était trop puissant pour vous. Vous êtes obligés de fuir." << std::endl;
                std::cout << "Votre quête se poursuivra une autre fois." << std::endl;
            }
            break;
    }

    std::cout << "À l'intérieur de la carrière, l'atmosphère devient de plus en plus oppressante." << std::endl;
    std::cout << "Que décidez-vous de faire ?" << std::endl;
    std::cout << "1. Avancer avec prudence dans les tunnels obscurs de ce lieu." << std::endl;
    std::cout << "2. Utiliser une torche pour éclairer votre chemin." << std::endl;

    std::cin >> choix;
    switch (choix) {
        case 1:
            std::cout << "Vous avancez lentement mais avec détermination dans les tunnels sombres de la carrière." << std::endl;
            std::cout << "Soudain, le Golem émerge des ombres, prêt à vous attaquer !" << std::endl;

        while (joueur->Alive() && golem->Alive()) {
                // Tour du joueur
                joueur->attaquer(golem);
                if (!golem->Alive()) {
                    std::cout << "Vous avez vaincu le Golem !" << std::endl;
                    break;
                }
                // Tour du Golem
                golem->attaquer(joueur);
                if (!joueur->Alive()) {
                    std::cout << "Malheureusement, le Golem était trop puissant pour vous. Vous êtes obligés de fuir." << std::endl;
                    std::cout << "Votre quête se poursuivra une autre fois." << std::endl;
                    break;
                }
            }
            break;
        case 2:
            std::cout << "Vous allumez une torche pour éclairer votre chemin dans les ténèbres de la carrière." << std::endl;
            std::cout << "Le Golem, attiré par la lumière, se jette sur vous dans un rugissement furieux !" << std::endl;

            while (joueur->Alive() && golem->Alive()) {
                joueur->attaquer(golem);
                if (golem->Alive()) {
                    golem->attaquer(joueur);
                }
            }

            if (!joueur->Alive()) {
                std::cout << "Malheureusement, le Golem était trop puissant pour vous. Vous êtes obligés de fuir" << std::endl;
                std::cout << "Votre quête se poursuivra une autre fois." << std::endl;
            }
            break;
            }
            if (joueur->Alive()){
                std::cout << "Après un rude combat, vous avez finalement vaincu le redoutable Golem." << std::endl;
                 std::cout << "Les habitants de la région seront reconnaissants pour votre courage et votre bravoure légendaires." << std::endl;
                std::cout << "Votre réputation continue de grandir dans tout le royaume." << std::endl;

                shared_ptr<Armure> explo{nullptr};
                int changerarmure;
                cout << "Vous trouvez un objet ! Il s'agit d'une armure :" << endl;
                explo = obtenirArmureAleatoire();
                explo->Infos();
                cout << "Vous possédez actuellement : " << endl;
                if (joueur->armure_ != nullptr) {
                     joueur->armure_->Infos();
                } else {
                 cout << "Aucune armure équipée." << endl;
                }
                cout << "Voulez-vous changer d'armure ? (1. Oui / 2. Non)" << endl;
                cin >> changerarmure;
                if (changerarmure == 1) {
                    joueur->setArmure(explo);
                    cout << "Vous avez équipé votre nouvelle armure." << endl;
                }
}
}

void Antre_du_Dragon(std::shared_ptr<Personnage> joueur) {
    std::cout << "Bienvenue, aventurier " << joueur->getNom() << "! Vous avez entendu parler d'un dragon terrifiant," << std::endl;
    std::cout << "résidant dans une grotte sombre au sommet de la montagne. On dit que le dragon" << std::endl;
    std::cout << "garde un trésor inestimable, mais peu osent s'aventurer dans son antre." << std::endl;
    std::cout << "Vous décidez de vous rendre à l'Antre du Dragon pour tenter de récupérer ce trésor légendaire. Cela vous permettra notamment de débarasser les bourgades environnantes de ce vil dragon." << std::endl;

    auto dragon = std::make_shared<Personnage>("Dragon", 150, 15, 10, 6, 8);
    dragon->setArme(std::make_shared<Arme>("Souffle de feu", 40));
    if (!joueur->arme_) {
    joueur->setArme(std::make_shared<Arme>("Vieille epee emoussee", 15));
}

    std::cout << "Vous commencez votre ascension périlleuse vers le sommet de la montagne. Le sentier est escarpé et dangereux," << std::endl;
    std::cout << "mais votre détermination à obtenir le trésor du dragon vous pousse à continuer." << std::endl;
    std::cout << "Après des heures de marche, vous atteignez enfin l'entrée de la grotte." << std::endl;
    std::cout << "L'obscurité intense à l'intérieur de la caverne vous enveloppe dès que vous franchissez le seuil." << std::endl;
    std::cout << "Votre cœur bat la chamade alors que vous avancez dans le noir, vos sens en alerte maximale." << std::endl;
    std::cout << "Que décidez-vous de faire ?" << std::endl;
    std::cout << "1. Explorer l'antre du dragon" << std::endl;
    std::cout << "2. Observer et vous préparer au combat" << std::endl;
    std::cout << "3. Contourner prudemment l'antre" << std::endl;

    int choix;
    std::cin >> choix;
    switch (choix) {
        case 1:
            std::cout << "Vous décidez de vous aventurer plus profondément dans l'antre du dragon, bravant les dangers et les mystères qui s'y cachent." << std::endl;
            std::cout << "Après un certain temps, vous parvenez à atteindre la chambre principale où repose le redoutable dragon." << std::endl;
            std::cout << "Votre cœur bat la chamade à l'idée du combat imminent." << std::endl;
            break;
        case 2:
            std::cout << "Vous choisissez de prendre un moment pour observer les alentours, cherchant des indices sur la nature du dragon et sur la meilleure façon de l'affronter." << std::endl;
            std::cout << "Vous remarquez les traces de griffes sur les murs et les ossements dispersés dans la caverne, témoins des batailles précédentes." << std::endl;
            std::cout << "Vous ajustez votre équipement et préparez votre esprit au combat à venir." << std::endl;
            break;
        case 3:
            std::cout << "Vous décidez de ne pas vous aventurer plus loin dans l'antre du dragon, conscient des dangers qui vous guettent." << std::endl;
            std::cout << "Au lieu de cela, vous choisissez de contourner la zone et de chercher un autre chemin pour atteindre votre objectif." << std::endl;
            std::cout << "Il est peut-être plus sage de tenter de prendre le dragon à revers." << std::endl;
            break;
        default:
            std::cout << "Vous hésitez un instant, incapable de décider de votre prochain mouvement." << std::endl;
            std::cout << "Cependant, le temps presse et vous devez prendre une décision." << std::endl;
            break;
    }

            std::cout << "Soudain, vous entendez un grondement sourd au loin, suivi du bruit de grandes ailes battant l'air." << std::endl;
            std::cout << "Que décidez-vous de faire ?" << std::endl;
            std::cout << "1. Continuer à avancer prudemment vers l'origine du bruit." << std::endl;
            std::cout << "2. Faire demi-tour et quitter la grotte." << std::endl;
            std::cin >> choix;

    switch (choix) {
        case 1:
            std::cout << "Vous serrez fermement votre arme et poursuivez votre chemin dans la pénombre." << std::endl;
            std::cout << "À mesure que vous avancez, la chaleur devient de plus en plus intense." << std::endl;
            std::cout << "Vous arrivez finalement dans une grande caverne illuminée par la lueur d'un immense feu." << std::endl;
            std::cout << "Là, devant vous, se tient le redoutable dragon, gardien de son trésor légendaire." << std::endl;
            std::cout << "Préparez-vous au combat !" << std::endl;

            while (joueur->Alive() && dragon->Alive()) {
                joueur->attaquer(dragon);
                if (!dragon->Alive()) {
                    std::cout << "Le dragon s'effondre, vaincu, et vous découvrez le trésor caché dans son antre !" << std::endl;
                    std::cout << "Vous avez réussi à surmonter tous les obstacles et à gagner le trésor !" << std::endl;
                    break;
                }
                dragon->attaquer(joueur);
                if (!joueur->Alive()) {
                    std::cout << "Malheureusement, le dragon vous a terrassé. Votre quête s'achève ici. Vous devez prendre du repos." << std::endl;
                    break;
                }
            }
            break;
            case 2:
                std::cout << "Vous décidez de faire demi-tour, n'osant pas affronter le dragon seul dans son antre." << std::endl;
                std::cout << "Vous rebroussez chemin et retournez à la civilisation, le trésor du dragon restant un mystère pour vous. Mais le dragon surgit dans votre dos !" << std::endl;
                while (joueur->Alive() && dragon->Alive()) {
                    joueur->attaquer(dragon);
                if (!dragon->Alive()) {
                    std::cout << "Le dragon s'effondre, vaincu, et vous découvrez le trésor caché dans son antre !" << std::endl;
                    std::cout << "Vous avez réussi à surmonter tous les obstacles et à gagner le trésor !" << std::endl;
                    break;
                }
                dragon->attaquer(joueur);
                if (!joueur->Alive()) {
                    std::cout << "Malheureusement, le dragon vous a terrassé. Votre quête s'achève ici. Vous devez vous reposer." << std::endl;
                    break;
                }
            }
            break;
            default:
                std::cout << "Vous restez immobile, paralysé par l'incertitude de la situation." << std::endl;
                std::cout << "Le dragon surgit soudainement de l'obscurité et vous attaque sans prévenir !" << std::endl;
            while (joueur->Alive() && dragon->Alive()) {
                    joueur->attaquer(dragon);
                if (!dragon->Alive()) {
                    std::cout << "Le dragon s'effondre, vaincu, et vous découvrez le trésor caché dans son antre !" << std::endl;
                    std::cout << "Vous avez réussi à surmonter tous les obstacles et à gagner le trésor !" << std::endl;
                    break;
                }
                dragon->attaquer(joueur);
                if (!joueur->Alive()) {
                    std::cout << "Malheureusement, le dragon vous a terrassé. Votre quête s'achève ici. Vous devez vous reposer." << std::endl;
                    break;
                }
            }
            break;
    }
    if (joueur->Alive()){
                std::cout << "Après vous êtes vaillement battu, vous triomphez du dragon." << std::endl;
                 std::cout << "Les habitants de la région vous remercient." << std::endl;
                std::cout << "Vos techniques de bataille se renforcent." << std::endl;

                shared_ptr<Armure> explo{nullptr};
                int changerarmure;
                cout << "Vous trouvez un objet dans le magnifique trésor du dragon ! Il s'agit d'une armure :" << endl;
                explo = obtenirArmureAleatoire();
                explo->Infos();
                cout << "Vous possédez actuellement : " << endl;
                if (joueur->armure_ != nullptr) {
                     joueur->armure_->Infos();
                } else {
                 cout << "Aucune armure équipée." << endl;
                }
                cout << "Voulez-vous changer d'armure ? (1. Oui / 2. Non)" << endl;
                cin >> changerarmure;
                if (changerarmure == 1) {
                    joueur->setArmure(explo);
                    cout << "Vous avez équipé votre nouvelle armure." << endl;
                }
}
}

void Antre_de_la_Chimere(std::shared_ptr<Personnage> joueur) {
    std::cout << "Bienvenue, aventurier " << joueur->getNom() << "! Des rumeurs persistantes circulent sur une créature mythique" << std::endl;
    std::cout << "connue sous le nom de Chimère, qui aurait élu domicile dans une ancienne grotte sacrée" << std::endl;
    std::cout << "au cœur de la forêt interdite. On dit que la Chimère possède un trésor unique, convoité" << std::endl;
    std::cout << "par de nombreux aventuriers intrépides, et qu'elle se nourrit de quiconque traverse la forêt." << std::endl;
    std::cout << "Vous décidez de vous rendre à l'Antre de la Chimère pour tenter de récupérer ce trésor légendaire et d'éliminer cette menace." << std::endl;

    auto chimere = std::make_shared<Personnage>("Chimère", 130, 13, 9, 5, 7);
    chimere->setArme(std::make_shared<Arme>("Morsure empoisonnée", 35));
    if (!joueur->arme_) {
    joueur->setArme(std::make_shared<Arme>("Vieille epee emoussee", 15));
}

    std::cout << "Vous pénétrez dans la forêt dense, où chaque arbre semble vous observer avec méfiance," << std::endl;
    std::cout << "comme s'il savait quel danger vous guette." << std::endl;
    std::cout << "Vous trouvez l'entrée de la grotte dissimulée derrière un rideau de lianes et de feuillages." << std::endl;
    std::cout << "L'atmosphère est lourde d'une étrange aura, et vous sentez le frisson de l'inconnu parcourir votre échine. L'odeur est pesante et répugnante." << std::endl;
    std::cout << "Que décidez-vous de faire ?" << std::endl;
    std::cout << "1. Pénétrer courageusement dans l'antre de la Chimère." << std::endl;
    std::cout << "2. Observer les environs et préparer votre stratégie." << std::endl;
    std::cout << "3. Chercher un autre chemin pour contourner la grotte." << std::endl;

    int choix;
    std::cin >> choix;
    switch (choix) {
        case 1:
            std::cout << "Vous serrez fermement votre arme et avancez dans l'obscurité, prêt à affronter la Chimère." << std::endl;
            std::cout << "À mesure que vous progressez, vous sentez la tension monter dans l'air, comme si quelque chose vous observait." << std::endl;
            std::cout << "La grotte s'élargit soudainement devant vous, révélant un espace sombre et sinistre où la Chimère pourrait se tapir." << std::endl;
            std::cout << "Votre cœur bat la chamade alors que vous vous préparez à l'inévitable combat." << std::endl;
            break;
        case 2:
            std::cout << "Vous prenez un moment pour observer les environs, scrutant chaque recoin de la grotte à la recherche d'un avantage." << std::endl;
            std::cout << "Vous remarquez les traces de pas et les empreintes de griffes laissées sur le sol, signes de la présence récente de la Chimère." << std::endl;
            std::cout << "Vous vous préparez mentalement au combat à venir, analysant les forces et les faiblesses de votre adversaire." << std::endl;
            break;
        case 3:
            std::cout << "Vous décidez de ne pas vous aventurer plus loin dans l'antre de la Chimère, conscient des dangers qui vous guettent." << std::endl;
            std::cout << "Au lieu de cela, vous cherchez un autre chemin pour contourner la grotte et atteindre votre objectif sans affronter la Chimère." << std::endl;
            std::cout << "Il pourrait être avantageux de débusquer le trésor sans avoir à affronter la Chimère." << std::endl;
            break;
        default:
            std::cout << "Vous hésitez un instant, incapable de décider de votre prochain mouvement." << std::endl;
            std::cout << "Cependant, le temps presse et vous devez prendre une décision." << std::endl;
            break;
    }
            std::cout << "Soudain, vous entendez un rugissement puissant résonner à travers la grotte, suivi du bruit de battements d'ailes." << std::endl;
            std::cout << "Que décidez-vous de faire ?" << std::endl;
            std::cout << "1. Affronter courageusement la Chimère." << std::endl;
            std::cout << "2. Fuir et abandonner votre quête." << std::endl;
            std::cin >> choix;
            switch (choix) {
                case 1:
                    std::cout << "Vous avancez avec détermination vers l'origine du bruit, prêt à faire face à la Chimère." << std::endl;
                    std::cout << "À mesure que vous approchez, la chaleur devient suffocante, signe de la présence imminente du monstre." << std::endl;
                    std::cout << "Vous vous retrouvez face à face avec la Chimère, une créature terrifiante aux multiples têtes et aux crocs acérés." << std::endl;
                    std::cout << "Préparez-vous au combat !" << std::endl;

                while (joueur->Alive() && chimere->Alive()) {
                joueur->attaquer(chimere);
                if (!chimere->Alive()) {
                    std::cout << "La Chimère gît vaincue à vos pieds, et vous découvrez enfin le trésor caché dans la grotte !" << std::endl;
                    std::cout << "Vous avez triomphé de tous les obstacles et acquis le trésor convoité ! Les passants n'ont plus rien à craindre." << std::endl;
                    break;
                }
                chimere->attaquer(joueur);
                if (!joueur->Alive()) {
                    std::cout << "Malheureusement, la Chimère vous a terrassé. La quête s'arrête là." << std::endl;
                    break;}
            }
            break;
        case 2:
            std::cout << "Vous décidez de faire demi-tour, réalisant que le combat contre la Chimère est au-delà de vos capacités actuelles." << std::endl;
            std::cout << "Vous quittez la grotte et retournez à la civilisation, laissant derrière vous le trésor de la Chimère et le danger qu'elle constitue. Mais la chimère surgit !" << std::endl;
            while (joueur->Alive() && chimere->Alive()) {
                joueur->attaquer(chimere);
                if (!chimere->Alive()) {
                    std::cout << "La Chimère gît vaincue à vos pieds, et vous découvrez enfin le trésor caché dans la grotte !" << std::endl;
                    std::cout << "Vous avez triomphé de tous les obstacles et acquis le trésor convoité !" << std::endl;
                    break;
                }
                chimere->attaquer(joueur);
                if (!joueur->Alive()) {
                    std::cout << "Malheureusement, la Chimère vous a terrassé. Votre quête prend fin ici. Vous allez vous soigner et prendre du repos." << std::endl;
                    break;
                }
            }
            break;
        default:
            std::cout << "Vous restez immobile, paralysé par l'incertitude de la situation." << std::endl;
            std::cout << "La Chimère surgit soudainement de l'obscurité et vous attaque sans prévenir !" << std::endl;
            while (joueur->Alive() && chimere->Alive()) {
                joueur->attaquer(chimere);
                if (!chimere->Alive()) {
                    std::cout << "La Chimère gît vaincue à vos pieds, et vous découvrez enfin le trésor caché dans la grotte !" << std::endl;
                    std::cout << "Vous avez triomphé de tous les obstacles et acquis le trésor convoité !" << std::endl;
                    break;
                }
                chimere->attaquer(joueur);
                if (!joueur->Alive()) {
                    std::cout << "Malheureusement, la Chimère vous a terrassé. Votre quête prend fin ici. Vous allez vous soigner et prendre du repos." << std::endl;
                    break;
                }
            }
            break;
    }
            if (joueur->Alive()){
                std::cout << "Vous voilà bien amochés après le combat, mais vous l'avez emporté." << std::endl;
                 std::cout << "La Chimère n'est plus, et son trésor est le votre." << std::endl;
                std::cout << "Votre réputation ne cesse de croître." << std::endl;

                shared_ptr<Armure> explo{nullptr};
                int changerarmure;
                cout << "Vous trouvez un objet dans le trésor de la Chimère ! Il s'agit d'une armure :" << endl;
                explo = obtenirArmureAleatoire();
                explo->Infos();
                cout << "Vous possédez actuellement : " << endl;
                if (joueur->armure_ != nullptr) {
                     joueur->armure_->Infos();
                } else {
                 cout << "Aucune armure équipée." << endl;
                }
                cout << "Voulez-vous changer d'armure ? (1. Oui / 2. Non)" << endl;
                cin >> changerarmure;
                if (changerarmure == 1) {
                    joueur->setArmure(explo);
                    cout << "Vous avez équipé votre nouvelle armure." << endl;
                }
}
}

bool gameOver = false;

auto creer_personnage(std::string name, std::string classe){
    std::shared_ptr<Personnage> perso;
    while (true) {
        if (classe == "Guerrier") {
            perso = std::make_shared<Guerrier>(name);
            break;
        }  
        else if (classe == "Mage") {
            perso = std::make_shared<Mage>(name);
            break;
        }
        else if (classe == "Archer") {
            perso = std::make_shared<Archer>(name);
            break;
        }
        else if (classe == "Voleur") {
            perso = std::make_shared<Voleur>(name);
            break;
        }
        else if (classe == "Paladin") {
            perso = std::make_shared<Paladin>(name);
            break;
        }
        else if (classe == "Barbare") {
            perso = std::make_shared<Barbare>(name);
            break;
        }
        else if (classe == "Assassin") {
            perso = std::make_shared<Assassin>(name);
            break;
        }
        else if (classe == "Invocateur") {
            perso = std::make_shared<Invocateur>(name);
            break;
        }
         else if (classe == "1") {
            gameOver = true;            
            break;
        }
        else {
            std::cout << "Erreur : personnage non reconnu. Veuillez choisir parmi Guerrier, Mage, Archer, Voleur, Paladin, Barbare, Assassin, ou Invocateur." << std::endl;
            std::cout << "Entrez à nouveau la classe du personnage : ";
            std::cin >> classe;
        }
    }
    std::cout << std::endl;
    perso->afficher();
    return perso;
};

int main() {
    std::cout << "\n---------------------------Bienvenue sur Légende des Anciens----------------------------" << std::endl
              << "-----------------------------------programmed by Axel------------------------------\n" << std::endl;

    int choixMenu;
    std::unique_ptr<Personnage> personnage;
    std::string nom;
    shared_ptr<Arme> exploration{nullptr};
    shared_ptr<Armure> explo{nullptr};
    vector<Quete> quetes;
    
    string name, classe;
    cout <<"Choisissez le nom de votre personnage : "<< endl;
    cin >> name;
    cout<< "Choisissez la classe de votre personnage parmi : \nGuerrier\nMage\nPaladin\nVoleur\nAssassin\nBarbare\nInvocateur\nArcher \n(ou faites 1 pour quitter le jeu) : "<<endl;
    cin >> classe;

    auto joueur = creer_personnage(name, classe);

    quetes.push_back(Quete("Récemment, de nombreuses disparitions sont à déplorer dans le village près de la carrière souterraine. Vous décidez d'aller aider les habitants de ce village.",Carriere_mystique,joueur));
    quetes.push_back(Quete("La rumeur court qu'un terrible dragon vit perché au sommet d'une montagne, et garde un trésor inestimable.",Antre_du_Dragon,joueur));
    quetes.push_back(Quete("Une forêt peu lointaine fait disparaître chaque personne qui ose s'y aventurer, et serait l'antre d'une créature terrifiante... ",Antre_de_la_Chimere,joueur));

    bool aTrouveSoins = false;

    while (joueur->Alive() && !gameOver) {
        cout << "Menu" << endl;
        cout << "2. Afficher mes stats" << endl;
        cout << "3. Explorer les alentours" << endl;
        cout << "4. Avancer sur les quêtes" << endl;
        cout << "5. Se soigner" << endl;
        cout << "1. Quitter le jeu" << endl;
        int choix;
        int changerarme;
        cin >> choix;

        switch (choix) {
            case 2:
                joueur->afficher();
                if (joueur->arme_ != nullptr) {
                joueur->arme_->afficherInfos();
                } else {
                cout << "Aucune arme équipée." << endl;
                }
                break;
            case 3:
                cout << "Vous partez explorer les alentours." << endl;
                cout << "Vous trouvez un objet ! Il s'agit d'une arme :" << endl;
                exploration = obtenirArmeAleatoire();
                exploration->afficherInfos();
                cout << "Vous trouvez également des soins !" << endl;
                aTrouveSoins = true;
                cout << "Vous possédez actuellement : " << endl;
                if (joueur->arme_ != nullptr) {
                     joueur->arme_->afficherInfos();
                } else {
                 cout << "Aucune arme équipée." << endl;
                }
                cout << "Voulez-vous changer d'arme ? (1. Oui / 2. Non)" << endl;
                cin >> changerarme;
                if (changerarme == 1) {
                    joueur->setArme(exploration);
                    cout << "Vous avez équipé votre nouvelle arme :" << endl;
                    exploration->afficherInfos();
                }
                break;
                case 1:
                cout << "Au revoir !" << endl;
                gameOver = true;
                break;
                default:
                cout << "Choix invalide. Veuillez sélectionner une option valide." << endl;
                break;
                case 5:
                     if (aTrouveSoins) {
                        joueur->Soins(30);
                            cout << "Vous vous soignez et récupérez 30 points de vie !" << endl;
                        aTrouveSoins = false;
                        } 
                        else {
                            cout << "Vous n'avez pas trouvé de soins lors de votre exploration." << endl;
                             }
                break;
                case 4:
                    cout << "Vous consultez les quêtes disponibles aux environs :" << endl;
                for (auto& quete : quetes) {
                    if (!quete.Terminee) {
                        cout << "- " << quete.description << endl;
                    }
                }
                cout << "Quelle quête voulez-vous commencer ?" << endl;
                for (int i = 0; i < quetes.size(); ++i) {
                    if (!quetes[i].Terminee) {
                        cout << i + 1 << ". " << quetes[i].description << endl;
                    }
                }
                int choixQuete;
                cin >> choixQuete;
                if (choixQuete >= 1 && choixQuete <= quetes.size()) {
                    quetes[choixQuete - 1].executer();
                    quetes[choixQuete - 1].terminer();
                    cout << "Quête terminée : " << quetes[choixQuete - 1].description << endl;
                } 

                else {
                    cout << "Choix invalide." << endl;
                }
                break;

}
bool toutesQuetesTerminees = true;
    for (auto& quete : quetes) {
        if (!quete.Terminee) {
            toutesQuetesTerminees = false;
            break;
        }
    }
    if (toutesQuetesTerminees) {
        cout << "Bravo ! Vous avez complété toutes les quêtes disponibles pour le moment" << endl;
        cout << "Revenez bientôt pour voir si de nouvelles quêtes sont apparues dans les environs." << endl;
        gameOver = true;
    }
}
}