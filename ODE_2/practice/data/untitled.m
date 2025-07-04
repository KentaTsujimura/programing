
% 変更したい数字のリスト
numbers = [3, 5, 10, 100];

% グラフの作成
figure;
hold on;

% 各数字に対してデータを読み込み、プロット
for i = 1:length(numbers)
    % 新しいファイル名を生成
    filename = sprintf('C1N%d.dat', numbers(i));

    % データの読み込み
    data = load(filename);

    % x, yデータの抽出
    x = data(:, 1); % 1列目をxデータとする
    y = data(:, 2); % 2列目をyデータとする

    % プロット
    plot(x, y, 'DisplayName', sprintf('y = %d * y3', numbers(i)));
end

% 凡例の追加
legend('show');
xlabel('Xデータ');
ylabel('Yデータ');
title('C1N.datのデータプロット');
hold off;