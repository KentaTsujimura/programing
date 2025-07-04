
% データを読み込む
data = load('data.dat'); % data.datファイルを読み込む

% x, y, zデータを抽出
x = data(:, 1); % 1列目をxデータとして取得
y = data(:, 2); % 2列目をyデータとして取得

% xとyのグラフを描画
figure; % 新しい図を作成
plot(x, y); % xとyのプロット
xlabel('X軸'); % X軸ラベル
ylabel('Y軸'); % Y軸ラベル
title('XとYのグラフ'); % グラフのタイトル
grid on; % グリッドを表示