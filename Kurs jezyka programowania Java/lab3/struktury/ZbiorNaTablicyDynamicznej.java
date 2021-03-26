package struktury;

public class ZbiorNaTablicyDynamicznej extends ZbiorNaTablicy {
    public ZbiorNaTablicyDynamicznej() {
        super(2);
    }

    @Override
    public void wstaw(Para p) throws Exception {
        for (Para k: arr) {
            if(k == null)
                continue;
            if(k.toString().equals(p.toString()))
                throw new Exception("wstaw: znaleziono pare o takim samym kluczu");
        }
        dodaj(p);
    }

    @Override
    public void usun(String k) {
        super.usun(k);
        if(cur_el < arr.length / 4)
            zmiana_rozmiaru(arr.length / 2);
    }

    @Override
    public void ustaw(Para p) throws Exception {
        for (Para k: arr) {
            if(k == null)
                continue;
            if(k.toString().equals(p.toString())) {
                k.setWartosc(p.getWartosc());
                return;
            }
        }
        dodaj(p);
    }

    @Override
    public void czysc() {
        super.czysc();
        Para[] newArr = new Para[2];
        arr = newArr;
    }

    @Override
    public void dodaj(Para p) {
        if(cur_el >= arr.length)
            zmiana_rozmiaru(arr.length * 2);
        arr[cur_el] = p;
        cur_el++;
    }

    public void zmiana_rozmiaru(int size) {
        Para[] newArr = new Para[size];
        for (int i = 0; i < cur_el; i++) {
            newArr[i] = arr[i];
        }
        arr = newArr;
    }
}
