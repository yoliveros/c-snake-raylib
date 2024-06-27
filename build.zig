const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});

    const optimize = b.standardOptimizeOption(.{});

    const exe = b.addExecutable(.{
        .name = "c-raylib",
        // .root_source_file = b.path("src/main.c"),
        .target = target,
        .optimize = optimize,
    });
    exe.addCSourceFile(.{
        .file = .{
            .src_path = .{
                .owner = b,
                .sub_path = "src/main.c",
            },
        },
        .flags = &.{"-std=c11"},
    });
    exe.linkLibC();

    const raylib = b.dependency("raylib", .{
        .target = target,
        .optimize = optimize,
    });

    exe.installLibraryHeaders(raylib.artifact("raylib"));
    exe.linkLibrary(raylib.artifact("raylib"));

    b.installArtifact(exe);

    const run_cmd = b.addRunArtifact(exe);

    run_cmd.step.dependOn(b.getInstallStep());

    if (b.args) |args| {
        run_cmd.addArgs(args);
    }

    const run_step = b.step("run", "Run the app");
    run_step.dependOn(&run_cmd.step);
}
