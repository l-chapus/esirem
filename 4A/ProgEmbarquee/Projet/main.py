import time
from tetris import Tetris


if __name__ == '__main__':
    try:
        game = Tetris()
        game.start()

        while True:
            game.display()
            time.sleep(1)

    except KeyboardInterrupt:
        pass
