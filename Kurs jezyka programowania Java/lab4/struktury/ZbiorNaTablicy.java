package struktury;

public class ZbiorNaTablicy extends Zbior {
    Para[] arr;
    int cur_el = 0;

    public ZbiorNaTablicy(int size) {
        if(size < 2) throw new IllegalArgumentException("ZbiorNaTablicy: rozmiar tablicy jest mniejszy od 2");

        arr = new Para[size];
    }

    @Override
    public Para szukaj(String k) throws Exception {
        for (Para p: arr) {
            if(p == null)
                continue;
            if(p.toString().equals(k)) return p;
        }
        throw new Exception("szukaj: nie znaleziono pary o podanym kluczu w zbiorze");
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
        int index = 0;
        for (Para p: arr) {
            if(p == null)
                continue;
            if(p.toString().equals(k)) {
                Para[] newArr = new Para[arr.length];
                for (int i = 0, j = 0; i < arr.length; i++) {
                    if (i == index) {
                        continue;
                    }
                    newArr[j++] = arr[i];
                }
                arr = newArr;
                cur_el--;
                return;
            }
            index++;
        }
    }

    @Override
    public double czytaj(String k) throws Exception {
        for (Para p: arr) {
            if(p == null)
                continue;
            if(p.toString().equals(k)) return p.getWartosc();
        }
        throw new Exception("czytaj: nie znaleziono pary o podanym kluczu w zbiorze");
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
        for (int i = 0; i < arr.length; i++) {
            arr[i] = null;
        }
        cur_el = 0;
    }

    @Override
    public int ile() {
        return cur_el;
    }

    public void dodaj(Para p) throws Exception {
        if(cur_el >= arr.length) throw new Exception("ustaw: osiagnieto maksymalny limit tablicy");
        arr[cur_el] = p;
        cur_el++;
    }

    public boolean search(String k) {
        for (Para p: arr) {
            if(p == null)
                continue;
            if(p.toString().equals(k)) return true;
        }
        return false;
    }
}
