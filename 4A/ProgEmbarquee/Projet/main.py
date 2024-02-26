import time

from application import Application

if __name__ == '__main__':
    try:
        game = Application()
        #game.start()

        while True:
            game.update()
            time.sleep(1)

    except KeyboardInterrupt:
        pass
