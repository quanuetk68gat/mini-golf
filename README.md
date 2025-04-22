1. Giới thiệu.

Mini-Golf là một trò chơi đánh golf mini, nơi người chơi điều khiển bóng để đưa nó vào lỗ với số lần đánh ít nhất có thể. Trò chơi được lập trình bằng C++ nhờ vào khả năng tối ưu hiệu suất và xử lý logic game mạnh mẽ của ngôn ngữ này. Sử dụng thư viện SDL2, trò chơi cung cấp giao diện đồ họa trực quan, âm thanh sống động và các hiệu ứng mượt mà. Các tính năng như tính điểm, nhiều màn chơi, hiệu ứng bóng đổ, và âm thanh khi đánh bóng giúp mang lại trải nghiệm thú vị và sinh động cho người chơi.

Trong phiên bản C++ của Mini-Golf, chương trình sử dụng các lớp như Ball, Tile, Hole, và RenderWindow để mô phỏng các thành phần trong trò chơi. Vị trí, vận tốc và trạng thái của bóng được xử lý thông qua các vector 2 chiều, trong khi các tile được sắp xếp để tạo thành các màn chơi khác nhau. Trò chơi được triển khai bằng giao diện đồ họa với thư viện SDL2, cho phép vẽ các đối tượng, xử lý âm thanh, font chữ, và sự kiện chuột. Người chơi điều khiển bóng bằng chuột để đưa bóng vào lỗ, và hệ thống sẽ tính điểm, đổi level, và hiển thị thông tin như số lượt đánh (strokes) và cấp độ (hole). Dự án có thể được mở rộng với nhiều màn chơi, hiệu ứng hình ảnh, hoặc hệ thống nhiều người chơi trên cùng màn hình.

2. Cách tải

Người chơi tải trực tiếp file "Mini-Golf.zip", trong đó đã có đầy đủ tài nguyên để có thể chạy game.

Sau khi tải thành công file ZIP, mở file và tìm file có tên "Mini-Golf" để mở game.

3. Cách chơi

🎯 Mục tiêu

Người chơi sẽ đánh quả bóng golf vào lỗ, người chơi oánh càng ít gậy thì sẽ là điểm tốt nhất.

🕹️ Cách chơi

Đây là hình ảnh đợi load game, có tên mình và lớp.

![image](https://github.com/user-attachments/assets/aca768a5-3de9-4e10-98de-4dcabc5e7cc6)

Và đây là màn hình đợi chính của game. Việc của người chơi là ấn chuột trái vào bất cứ đâu trong màn hình để chơi.

![image](https://github.com/user-attachments/assets/d03ae723-af42-4a0e-8941-c0ade9ad86d3)

Người chơi sẽ phải dùng chuột để định hướng/ đánh quả bóng golf vào lỗ, và cái khó của game là người chơi sẽ phải chơi 2 lỗ riêng biệt cùng 1 lúc.Và sẽ có 10 lỗ để cho người chơi.
![image](https://github.com/user-attachments/assets/df0bc40a-6f98-432b-a7f7-9cd4b9c34da7)

Sau khi người chơi hoàn thành hết các lỗ thì game sẽ hiện ra là đã hoàn thành và số gậy bạn đánh. Số gậy đánh càng ít thì sẽ càng thành công.
![image](https://github.com/user-attachments/assets/f943a132-58cd-4145-ad35-722770c02a76)

✅ Mẹo

Quan sát kĩ các đường đi của bóng, có thể có có đường 1 gậy mà bóng của cả 2 lỗ sẽ đều vào thành công.

4. Về source code game:

🎮 Gameplay & Logic

- "Ball", "Hole", "Tile": Các class đại diện cho trái bóng, hố golf và mặt sân.
- "loadTiles()": Hàm khởi tạo bản đồ cho từng level.
- "update()": Cập nhật vị trí bóng, xử lý va chạm, tính toán lực đánh và điều kiện thắng.
- "loadLevel(int level)": Reset trạng thái bóng và hố mỗi khi sang màn mới.
- "getStrokeText()", "getLevelText()": Hiển thị số lượt đánh và tên màn chơi.

🖼️ Đồ họa và âm thanh (SDL2_image, SDL2_ttf, SDL2_mixer)

- "loadTexture()": Tải ảnh ".png" từ thư mục "res/gfx/".
- "render()", "renderCenter()": Hiển thị bóng, điểm số, giao diện và các hiệu ứng động.
- "TTF_OpenFont()": Tải font chữ để hiển thị điểm và tiêu đề.
- "Mix_PlayChannel()": Chơi hiệu ứng âm thanh như đánh trúng hố, va chạm…

🕹️ Xử lý sự kiện (SDL_Event)

Toàn bộ sự kiện được xử lý **trực tiếp trong "update()" và "titleScreen()"**, gồm:

- "SDL_MOUSEBUTTONDOWN": Người chơi nhấn chuột trái để bắt đầu tích lực hoặc vào game.
- "SDL_MOUSEBUTTONUP": Thả chuột để đánh bóng.
- "SDL_QUIT": Thoát game khi đóng cửa sổ.

Các biến "mouseDown" và "mousePressed" kiểm soát hành vi giữ và nhấn mới.

🖼️ Ảnh nền & kết quả Tải các ảnh:

"bg.png" làm nền bảng chơi

![bg](https://github.com/user-attachments/assets/79a55b83-0de4-43f6-95f7-a709f46f3a1f)

"logo.png" làm logo game

![logo](https://github.com/user-attachments/assets/b1744c53-8af9-465b-8d90-5929f5ad3605)

"ball.png" quả bóng golf

![ball](https://github.com/user-attachments/assets/39bc1b4d-87bf-4dc0-a1be-755ab31a79cb)

"hole.png" hố golf

![hole](https://github.com/user-attachments/assets/eda5882d-247b-4730-98ba-e629a074a6fb)

"point.png" mũi tên hướng đi của bóng golf

![point](https://github.com/user-attachments/assets/d9348bc7-664e-472d-9e52-0ed6f725f6a0)

🧪 Tệp liên quan:

"resource/gfx/": Hình ảnh (.png) cho sân golf, bóng, giao diện, logo.

"resource/font/": Font chữ "font.ttf".

"resource/sfx/": Âm thanh (.mp3) như swing, hole-in, charge.

✅ Điểm nổi bật

- Giao diện sinh động bằng SDL2 với hiệu ứng bóng và giao diện hoạt họa.
- Cơ chế đánh bóng sử dụng lực dựa trên thời gian giữ chuột.
- Có nhiều màn chơi khác nhau được nạp bằng "loadLevel()".
- Âm thanh hiệu ứng giúp game thêm hấp dẫn.
