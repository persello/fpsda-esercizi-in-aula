struct angolo
{
    int gradi;
    int primi;
    double secondi;
};

struct angolo leggi_angolo(void);
void stampa_angolo(struct angolo alpha);
struct angolo somma_angoli(struct angolo alpha, struct angolo beta);
struct angolo normalizza_angolo(struct angolo alpha);