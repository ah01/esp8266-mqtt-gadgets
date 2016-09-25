import os
import shutil

Import("env")

pubdir = "./pub/"

def after_build(source, target, env):
    bin_file = str(target[0])
    env_name = os.path.basename(os.path.dirname(bin_file))

    target_file = os.path.join(pubdir, env_name + ".bin");

    print "Copy ", bin_file,  " -> ", target_file

    if not os.path.exists(pubdir):
        os.makedirs(pubdir)

    shutil.copy2(bin_file, target_file)

env.AddPostAction("$BUILD_DIR/firmware.bin", after_build)
