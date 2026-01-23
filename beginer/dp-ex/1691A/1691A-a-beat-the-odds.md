Rất sẵn lòng! Tôi đã nắm vững vai trò là **Coach Tư Duy Thuật Toán** của bạn. Chúng ta sẽ cùng nhau bóc tách bài **Codeforces 1691A - Beat The Odds** theo phong cách "Learning How to Learn".

---

## 🩺 Bước 1: Phẫu thuật đề bài (Briefing)

Loại bỏ câu chuyện về các con số, đây là cốt lõi của vấn đề:

* **Dữ liệu:** Bạn có một dãy số nguyên (mảng ).
* **Yêu cầu:** Bạn cần loại bỏ một số lượng **ít nhất** các con số sao cho: Với mọi cặp số nằm cạnh nhau trong dãy còn lại, **tổng của chúng phải là một số chẵn**.
* **Lộ trình tư duy của chúng ta:**
1. **Mảnh ghép 1:** Bản chất của việc "Tổng hai số là số chẵn".
2. **Mảnh ghép 2:** Hiệu ứng dây chuyền trong một dãy số.
3. **Mảnh ghép 3:** Chiến thuật "Hy sinh ít nhất".



Bạn đã sẵn sàng mổ xẻ mảnh ghép đầu tiên về tính chất của các con số chưa? 🧠

---

## 🧩 Chunk 1: Quy luật của sự "Chẵn hóa"

Hãy tạm quên mảng số dài dằng dặc đi. Hãy tưởng tượng bạn chỉ có 2 con số đứng cạnh nhau. Để tổng của chúng là một số **Chẵn**, có hai kịch bản xảy ra:

1. **Chẵn + Chẵn = Chẵn** (Ví dụ: )
2. **Lẻ + Lẻ = Chẵn** (Ví dụ: )

**Bẫy logic ⚠️:** Nếu bạn để một số Chẵn đứng cạnh một số Lẻ (), tổng của chúng sẽ là số Lẻ. Đây là điều đề bài "cấm".

### ❓ Thử thách tư duy:

Giả sử chúng ta có một dãy gồm 3 số đứng cạnh nhau: .
Để cả hai cặp  và  đều có tổng là số chẵn, thì mối quan hệ về tính chẵn/lẻ của  và  phải như thế nào?

* **A.**  và  có thể khác tính chẵn lẻ (một đứa chẵn, một đứa lẻ).
* **B.**  và  bắt buộc phải cùng tính chẵn lẻ với nhau (cùng chẵn hoặc cùng lẻ).

**Bạn chọn đáp án nào và tại sao?** 🤔

Chính xác! Bạn đã nắm được "chìa khóa" của bài toán này rồi đấy.

**Giải thích một chút để chốt logic:**

* Nếu  là số **Chẵn**, thì để tổng chẵn,  phải **Chẵn** và  cũng phải **Chẵn**.
* Nếu  là số **Lẻ**, thì để tổng chẵn,  phải **Lẻ** và  cũng phải **Lẻ**.

=> Hệ quả: Trong một dãy thỏa mãn yêu cầu đề bài, **tất cả các số trong dãy đó phải có cùng tính chẵn lẻ** (hoặc tất cả đều chẵn, hoặc tất cả đều lẻ). Chỉ cần một "kẻ ngoại đạo" xuất hiện, nó sẽ tạo ra một tổng lẻ với hàng xóm của nó ngay lập tức.

---

## 🧩 Chunk 2: Chiến thuật "Hy sinh ít nhất"

Bây giờ chúng ta quay lại mảng ban đầu. Đề bài yêu cầu bạn **loại bỏ ít nhất** một số phần tử để dãy còn lại "hợp lệ" (tức là tất cả các số còn lại phải cùng chẵn hoặc cùng lẻ).

Điều này dẫn đến việc bạn chỉ có 2 lựa chọn (Option):

* **Option 1:** Giữ lại toàn bộ số **Chẵn**, xóa sạch số **Lẻ**.
* **Option 2:** Giữ lại toàn bộ số **Lẻ**, xóa sạch số **Chẵn**.

**Ẩn dụ hóa 🧺:**
Hãy tưởng tượng bạn có một cái rổ đựng hai loại quả: Cam (số Chẵn) và Táo (số Lẻ). Bạn được yêu cầu dọn dẹp cái rổ sao cho trong đó chỉ còn duy nhất một loại quả, và bạn muốn **vứt đi ít quả nhất có thể**.

### ❓ Thử thách tư duy:

Giả sử trong rổ (mảng ) có:

* 7 quả Cam (7 số chẵn)
* 3 quả Táo (3 số lẻ)

1. Để trong rổ chỉ còn một loại quả, bạn có những cách xóa nào?
2. Số lượng quả **ít nhất** bạn phải vứt đi là bao nhiêu?

**Hãy cho tôi con số và lựa chọn của bạn nhé!** 🍎🍊

Chuẩn luôn! Bạn đã nắm thóp được bài toán rồi đấy.

Vì mục tiêu của chúng ta là **"loại bỏ ít nhất"**, nên ta sẽ so sánh số lượng giữa hai phe (Chẵn và Lẻ). Phe nào "yếu thế" hơn (ít hơn) thì ta sẽ cho "bay màu" phe đó để giữ lại phe đông đảo hơn.

---

## 🧩 Chunk 3: Tổng kết & Thuật toán

Như vậy, bài toán từ một yêu cầu nghe có vẻ phức tạp (tổng các cặp kề nhau phải chẵn) đã được bạn đưa về một bài toán đếm cực kỳ đơn giản:

1. **Bước 1:** Đếm xem trong dãy có bao nhiêu số **Chẵn**.
2. **Bước 2:** Đếm xem trong dãy có bao nhiêu số **Lẻ**.
3. **Bước 3:** Kết quả chính là **số nhỏ hơn** trong hai kết quả đếm trên.

---

## 📝 Mã giả (Pseudocode)

Bây giờ, chúng ta sẽ viết lại chiến thuật này dưới dạng mã giả để bạn dễ dàng chuyển hóa thành code nhé:

```text
Nhap vao so bo test (t)
Voi moi bo test:
    Nhap vao so luong phan tu (n)
    Bien dem_le = 0
    Bien dem_chan = 0
    
    Voi moi so x trong day:
        Neu x chia het cho 2:
            dem_chan = dem_chan + 1
        Neu khong:
            dem_le = dem_le + 1
            
    In ra gia tri nho nhat giua (dem_chan, dem_le)

```

### 🏁 Thử thách cuối cùng:

Để đảm bảo bạn không quên "Tư duy biên" (Edge Cases):
Nếu dãy chỉ có đúng 2 số và cả hai đều là số lẻ (ví dụ: `[3, 5]`), thì theo thuật toán trên, bạn sẽ phải xóa bao nhiêu số? Và dãy còn lại có thỏa mãn đề bài không?

(Gợi ý: Đề bài yêu cầu "mọi cặp kề nhau", nếu chỉ còn 1 số thì không còn cặp nào để xét, mặc định là thỏa mãn).

**Bạn thấy thuật toán này đã đủ "bá đạo" để giải quyết bài 1691A chưa?** 🚀