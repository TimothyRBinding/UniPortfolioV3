import { Entity, Column, PrimaryGeneratedColumn } from 'typeorm'

@Entity()
export class ProfileImage {
    @PrimaryGeneratedColumn()
    id: number

    @Column()
    image: Buffer
}
