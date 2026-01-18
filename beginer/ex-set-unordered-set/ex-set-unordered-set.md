Chào bạn! Việc luyện tập theo nhóm chủ đề là cách tốt nhất để tạo ra các "chunk" kiến thức vững chắc. Dưới đây là danh sách các bài tập trên Codeforces ở tầm **Elo 800-1000**, tập trung vào việc sử dụng `set` và `unordered_set`.

Vì `set` (tự động sắp xếp, ) và `unordered_set` (không sắp xếp, ) đều dùng để lưu trữ các phần tử duy nhất, các bài này sẽ giúp bạn thành thạo cả hai.

---

## Danh sách 20 bài tập Codeforces (Elo 800 - 1000)

| STT | Tên bài & Link | Dịch đề bài vắn tắt | Chiến lược (Hint) |
| --- | --- | --- | --- |
| 1 | [Boy or Girl (236A)](https://codeforces.com/problemset/problem/236/A) | Đếm số ký tự khác nhau trong tên. | Đưa các ký tự vào `set`, kiểm tra `size()` là chẵn hay lẻ. |
| 2 | [Is your horseshoe on the other hoof? (228A)](https://codeforces.com/problemset/problem/228/A) | Cho 4 màu móng ngựa, cần mua thêm bao nhiêu để có 4 màu khác nhau? | Số cần mua = 4 - `set.size()`. |
| 3 | [Pangram (520A)](https://codeforces.com/problemset/problem/520/A) | Kiểm tra chuỗi có chứa đủ 26 chữ cái tiếng Anh không. | Chuyển hết về chữ thường, bỏ vào `set`. Kiểm tra `size() == 26`. |
| 4 | [Registration System (4C)](https://codeforces.com/problemset/problem/4/C) | Quản lý tên người dùng, nếu trùng thì thêm số thứ tự. | Dùng `map` để đếm số lần xuất hiện của tên. (Bài này chuyển tiếp từ set sang map). |
| 5 | [Anton and Letters (443A)](https://codeforces.com/problemset/problem/443/A) | Đếm các chữ cái khác nhau trong tập hợp `{a, b, c}`. | Xử lý chuỗi để lấy chữ cái, bỏ vào `set` rồi in ra `size()`. |
| 6 | [I Wanna Be the Guy (469A)](https://codeforces.com/problemset/problem/469/A) | Hai người có thể vượt qua tất cả  màn chơi không? | Hợp (Union) các màn chơi của 2 người vào 1 `set`. Kiểm tra `size() == n`. |
| 7 | [Arrival of the General (144A)](https://codeforces.com/problemset/problem/144/A) | Tìm vị trí Max và Min để hoán đổi. | (Luyện tập tìm vị trí, set có thể dùng để lưu các giá trị duy nhất nếu cần). |
| 8 | [Gamer Hemose (1592A)](https://codeforces.com/problemset/problem/1592/A) | Chọn 2 vũ khí mạnh nhất để tiêu diệt quái vật. | Dùng `set` (hoặc sort) để lấy ra 2 giá trị lớn nhất duy nhất. |
| 9 | [Double Strings (1703D)](https://codeforces.com/problemset/problem/1703/D) | Kiểm tra một chuỗi có bằng tổng 2 chuỗi khác trong danh sách không. | Bỏ tất cả chuỗi vào `unordered_set`. Với mỗi chuỗi, cắt làm đôi và check `count()`. |
| 10 | [Favorite Sequence (1462A)](https://codeforces.com/problemset/problem/1462/A) | Khôi phục dãy số bị xáo trộn từ hai đầu. | (Luyện tập về cấu trúc dữ liệu, có thể dùng `set` để đánh dấu). |
| 11 | [Two-gram (977B)](https://codeforces.com/problemset/problem/977/B) | Tìm cặp 2 ký tự xuất hiện nhiều nhất. | Dùng `map<string, int>` để đếm các cặp con. |
| 12 | [Polycarp and Letters (864B)](https://codeforces.com/problemset/problem/864/B) | Tìm đoạn con dài nhất chỉ chứa chữ thường khác nhau. | Duyệt chuỗi, gặp chữ hoa thì `clear()` set, gặp chữ thường thì `insert()`. |
| 13 | [Black Square (431A)](https://codeforces.com/problemset/problem/431/A) | Tính calo khi chạm vào các vùng màn hình. | Dùng mảng hoặc `map` ánh xạ vị trí sang calo. |
| 14 | [Keyboard (474A)](https://codeforces.com/problemset/problem/474/A) | Dịch chuyển ký tự sang trái/phải trên bàn phím. | Lưu bàn phím vào string, dùng `find` để tìm vị trí. |
| 15 | [Remove Smallest (1399A)](https://codeforces.com/problemset/problem/1399/A) | Xóa phần tử sao cho khoảng cách giữa chúng . | `sort` mảng hoặc dùng `set` để duyệt các phần tử liên tiếp. |
| 16 | [Distinct Digits (1228A)](https://codeforces.com/problemset/problem/1228/A) | Tìm số trong đoạn  có các chữ số khác nhau. | Chuyển số thành string, bỏ từng chữ số vào `set`. Nếu `size() == string.length()` là đạt. |
| 17 | [Presents (136A)](https://codeforces.com/problemset/problem/136/A) | Ai tặng quà cho ai? (Hoán vị). | Dùng mảng hoặc `map` để đảo ngược vị trí. |
| 18 | [Short Substrings (1367A)](https://codeforces.com/problemset/problem/1367/A) | Khôi phục chuỗi gốc từ chuỗi đã nhân đôi các cặp. | Duyệt bước nhảy 2 để lấy ký tự. |
| 19 | [Odd Queries (1807D)](https://codeforces.com/problemset/problem/1807/D) | Thay đổi mảng và kiểm tra tổng là chẵn hay lẻ. | Dùng mảng cộng dồn (Prefix Sum). |
| 20 | [Cipher Shifer (1840A)](https://codeforces.com/problemset/problem/1840/A) | Giải mã chuỗi theo quy tắc ký tự lặp lại. | Dùng vòng lặp và đánh dấu điểm dừng. |

---

## 💡 Lời khuyên khi giải bài

* **Tại sao lại có Map ở đây?** Bạn sẽ thấy trong danh sách có một số bài dùng `map`. Trong CP, `set` và `map` là "anh em". Nếu `set` dùng để biết "có tồn tại hay không", thì `map` dùng để biết "tồn tại bao nhiêu lần".
* **Khi nào dùng Unordered?** Ở tầm Elo 800-1000, dữ liệu thường nhỏ ( hoặc ), nên `std::set` (có sắp xếp) vẫn chạy rất tốt. Hãy tập dùng `std::set` trước để quen với việc các phần tử luôn được sắp xếp tăng dần.

**Bạn có muốn mình giải chi tiết bài đầu tiên (Boy or Girl) bằng cả 2 cách: dùng `set` truyền thống và dùng `unordered_set` của C++11/17 không?**